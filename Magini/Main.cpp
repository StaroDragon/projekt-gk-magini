

#include <stdio.h>
#include <string.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>
#include "Pipeline.h"
#include "Controls.h"
#include "MainShader.h"
#include "Map.h"
#include "Player.h"
#include "GameDefs.h"
#include "EndPoint.h"
#include "TextRenderer.h"



std::vector<Shader*> shaders;

Keyboard keyboard;
Map* map;
Player* player = NULL;
EndPoint* endpoint = NULL;
TextRenderer* textRenderer = NULL;
std::vector<Object*> enemies;
int timeFromStart=0;
int oldTimeFromStart=0;
int deltaTime;


static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static float Scale = 0.0f;
	Scale += 0.001f;



	Pipeline p;
	p.Scale(0.1f);
	p.SetCamera(player->GetCamera());
	p.SetPerspective(player->GetPerspective());
	player->Render(shaders, p.GetVPTranslation());
	endpoint->Render(shaders, p.GetVPTranslation());
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Render(shaders, p.GetVPTranslation());
	}
	map->RenderMap(shaders, p.GetVPTranslation());
	timeFromStart = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = timeFromStart - oldTimeFromStart;
	oldTimeFromStart = timeFromStart;
	keyboard.ProcessKeyboard(player);
	player->ProcessChange(*map,endpoint,enemies, deltaTime, textRenderer);
	endpoint->ProcessChange(*map, deltaTime);


	glm::mat4 mvp = p.GetMVPTranslation();
	glutSwapBuffers();
}


static void KeyDown(unsigned char key, int x, int y)
{
	keyboard.KeyDown(key);
}
static void KeyUp(unsigned char key, int x, int y)
{
	keyboard.KeyUp(key);
}
static void SpecialKeyDown(int key, int x, int y)
{

}
static void SpecialKeyUp(int key, int x, int y)
{

}

static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
	glutIdleFunc(RenderSceneCB);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutSpecialFunc(SpecialKeyDown);
	glutSpecialUpFunc(SpecialKeyUp);
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Magini");


	InitializeGlutCallbacks();

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	MainShader* mainshader = new MainShader();
	if (!mainshader->Init())
	{
		return false;
	}
	mainshader->Enable();
	shaders.push_back(mainshader);

	textRenderer = new TextRenderer(WINDOW_WIDTH, WINDOW_HEIGHT);
	textRenderer->Load("../Data/Fonts/arial.ttf", 24);

	player = new Player();
	endpoint = new EndPoint();

	map = new Map();
	map->LoadMap("../Data/Map.txt",player,endpoint,enemies);


	glutMainLoop();

	return 0;
}