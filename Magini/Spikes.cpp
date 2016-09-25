#include "Spikes.h"
#include "Pipeline.h"

Spikes::Spikes()
{
	height = TILE_HEIGHT;
	width = TILE_WIDTH + 5;
	direction = LEFT;
	canJump = true;

	this->xv = 0;
	this->yv = 0;

	mesh = new Mesh();

	mesh->LoadMesh("../Data/Spikes/cmn_obj_thorn_SD.obj");
}

Spikes::Spikes(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	height = TILE_HEIGHT;
	width = TILE_WIDTH + 5;
	direction = LEFT;
	canJump = true;

	mesh = new Mesh();

	mesh->LoadMesh("../Data/Spikes/cmn_obj_thorn_SD.obj");
}

void Spikes::Render(std::vector<Shader*> shaders, glm::mat4 VP)
{
	Pipeline p;
	p.Position(x + (width / 2), y, z);
	MainShader* shader = dynamic_cast<MainShader*>(shaders[0]); //MainShader
	shader->Enable();
	shader->SetMVP(p.GetMVPTranslation(VP));
	mesh->Render();
	this->DrawBox(x, x + width, y, y + height, z, z + TILE_DEPTH, shaders, VP);
}