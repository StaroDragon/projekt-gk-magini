#include "StaticObject.h"
#include "Pipeline.h"

BasicTile::BasicTile(float x, float y,float z)
{
	this->x = x;
	this->y = y;
	this->z = z;

	height = TILE_HEIGHT;
	width = TILE_WIDTH;
	Vertex Vertices[] =
	{
		Vertex(glm::vec3(0.0f, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, -TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),

		Vertex(glm::vec3(0.0f, 0.0f, TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),

		Vertex(glm::vec3(0.0f, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),

		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),

		Vertex(glm::vec3(0.0f, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, -TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, 0.0f, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, 0.0f, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),

		Vertex(glm::vec3(0.0f, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, TILE_HEIGHT, TILE_DEPTH / 2), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f)),
		Vertex(glm::vec3(0.0f, TILE_HEIGHT, -TILE_DEPTH / 2), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f)),
	};
	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	texture = new Texture(GL_TEXTURE_2D, "../Data/bricks.jpg");
	texture->Load();


}

void BasicTile::Render(std::vector<Shader*> shaders, glm::mat4 VP)
{
	Pipeline p;
	p.Position(x, y, z);
	MainShader* shader = dynamic_cast<MainShader*>(shaders[0]); //MainShader
	shader->Enable();
	shader->SetMVP(p.GetMVPTranslation(VP));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);
	glBindBuffer(GL_ARRAY_BUFFER, VB);

	texture->Bind(GL_TEXTURE0);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}