#include "EndPoint.h"
#include "Pipeline.h"


EndPoint::EndPoint()
{
	height = TILE_HEIGHT*2+5;
	width = TILE_WIDTH/2;
	direction = LEFT;
	canJump = true;

	this->xv = 0;
	this->yv = 0;

	mesh = new Mesh();

	mesh->LoadMesh("../Data/Flag/flag.obj");
}

EndPoint::EndPoint(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	height = TILE_HEIGHT*2;
	width = TILE_WIDTH + 5;
	direction = LEFT;
	canJump = true;

	mesh = new Mesh();

	mesh->LoadMesh("../Data/Flag/flag.obj");
}

void EndPoint::Render(std::vector<Shader*> shaders, glm::mat4 VP)
{
	Pipeline p;
	p.Scale(0.1f);
	p.Position(x+(width/2), y, z);
	MainShader* shader = dynamic_cast<MainShader*>(shaders[0]); //MainShader
	shader->Enable();
	shader->SetMVP(p.GetMVPTranslation(VP));
	mesh->Render();
	//this->DrawBox(x, x + width, y, y + height, z, z + TILE_DEPTH, shaders, VP);
}
