#include "Player.h"
#include "Pipeline.h"
#include <sstream>

Player::Player()
{
	height = TILE_HEIGHT-3;
	width = TILE_WIDTH+5;
	direction = LEFT;
	canJump = true;
	walking = false;
	hitpoints = STARTING_HITPOINTS;
	invuTime = 0.0f;
	invu = false;
	gameState = GAME_ACTIVE;

	camera = new Camera(glm::vec3(x, y, z - TILE_DEPTH), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	perspective = PerspectiveInfo(45.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 1.0f, 1000.0f);

	mesh = new Mesh();

	mesh->LoadMesh("../Data/Spider/spider.obj");
}

Player::Player(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	height = TILE_HEIGHT-3;
	width = TILE_WIDTH + 5;
	direction = LEFT;
	canJump = true;
	hitpoints = STARTING_HITPOINTS;
	invuTime = 0.0f;
	invu = false;
	gameState = GAME_ACTIVE;

	camera = new Camera(glm::vec3(x, y, z - TILE_DEPTH), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	perspective = PerspectiveInfo(45.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 1.0f, 1000.0f);

	mesh = new Mesh();

	mesh->LoadMesh("../Data/Spider/spider.obj");

}

void Player::Render(std::vector<Shader*> shaders, glm::mat4 VP)
{
	Pipeline p;
	p.Scale(0.1f);
	p.Position(x+(width/2), y+(height/2), z);
	//
	if (direction == RIGHT)
	{
		p.Rotate(3.0f, 0.0f, 1.0f, 0.0f);
	}
	MainShader* shader = dynamic_cast<MainShader*>(shaders[0]); //MainShader
	shader->Enable();
	shader->SetMVP(p.GetMVPTranslation(VP));
	mesh->Render();
	this->DrawBox(x, x + width, y, y + height, z, z + TILE_DEPTH, shaders, VP);
}

void Player::AdjustCamera()
{
	camera->SetCameraPosition(glm::vec3(x, y, z + TILE_DEPTH*10));
}

Camera Player::GetCamera()
{
	return *camera;
}

PerspectiveInfo Player::GetPerspective()
{
	return perspective;
}

void Player::ProcessChange(Map map, Object* endpoint, std::vector<Object*> enemies, int deltaTime, TextRenderer *textRenderer)
{
	if (invu)
	{
		float fdelta = (float)deltaTime;
		invuTime -=fdelta / 1000;
		printf("Remaining %f\n", invuTime);
		if (invuTime <= 0.0f)
		{
			invu = false;
		}
	}
	DynamicObject::ProcessChange(map,deltaTime);
	if (DynamicCollision(endpoint) && (gameState!=GAME_FAILURE))
	{
		printf("Collision\n");
		gameState = GAME_BEAT;
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		if (DynamicCollision(enemies[i]))
		{
			if (!invu)
			{
				invu = true;
				invuTime = INVU_TIME;
				hitpoints -= 1;
				printf("Hit\n");
			}
		}
	}
	if (hitpoints <= 0 && (gameState!=GAME_BEAT))
	{
		gameState = GAME_FAILURE;
	}
	AdjustCamera();
	DisplayUI(textRenderer);
}

void Player::ChangePosition(float x, float y, float z)
{
	Object::ChangePosition(x, y, z);
	AdjustCamera();
}

void Player::DisplayUI(TextRenderer *textRenderer)
{
	std::stringstream ss;
	switch (gameState)
	{
	case GAME_ACTIVE:
		ss << this->hitpoints;
		textRenderer->RenderText("Hitpoints: " + ss.str(), 5.0f, 5.0f, 1.0f);
		break;
	case GAME_BEAT:
		textRenderer->RenderText("You beat the game!", WINDOW_WIDTH / 2.3, WINDOW_HEIGHT / 2, 1.0f);
		break;
	case GAME_FAILURE:
		textRenderer->RenderText("You have lost", WINDOW_WIDTH / 2.1, WINDOW_HEIGHT / 2, 1.0f);
	}
}