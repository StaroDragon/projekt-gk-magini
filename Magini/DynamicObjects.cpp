#include "DynamicObjects.h"
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "Pipeline.h"

bool DynamicObject::StaticCollision(Object* object, Object* &rightCol, Object* &leftCol, Object* &upCol, Object* &downCol)
{
	int tileX, tileY;
	if (xv > 0)
	{
		if (DynamicCollision(object,x+width/2+xv,x+xv+width,y+1.0f,y+height-1.0f,z,TILE_DEPTH)) //Prawo
		{
			rightCol = object;
		}
	}
	else if (xv < 0)
	{
		if (DynamicCollision(object, x + xv,x+xv+width/2, y + 1.0f, y+height - 1.0f, z, TILE_DEPTH)) //Lewo
		{
			leftCol = object;
		}
	}

	if (yv > 0)
	{
		if (DynamicCollision(object, x+1.0f, x+width-1.0f, y + yv, y+height, z, TILE_DEPTH)) //Sufit
		{
			upCol = object;
		}
	}
	else
	{
		if (DynamicCollision(object, x + 1.0f, x+width - 1.0f, y + yv, y+2.0f, z, TILE_DEPTH)) //Podloga
		{
			downCol = object;
		}
	}
	return false;
}

void DynamicObject::MoveRight()
{
	xv = MOVEMENT_SPEED;
	direction = RIGHT;
}

void DynamicObject::MoveLeft()
{
	xv = -MOVEMENT_SPEED;
	direction = LEFT;
}

void DynamicObject::Jump()
{
	if (canJump)
	{
		yv = JUMP_STRENGTH;
		canJump = false;
		walking = false;
	}
	
}

void DynamicObject::Stop()
{
	xv = 0;
}

bool DynamicObject::DynamicCollision(Object* object)
{
	if (this->x < object->x + object->width &&
		this->x + this->width > object->x &&
		this->y < object->y + object->height &&
		this->y + this->height > object->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool DynamicObject::DynamicCollision(Object* object, float x, float y, float z)
{
	if (x < object->x + object->width &&
		x + this->width > object->x &&
		y < object->y + object->height &&
		y + this->height > object->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool DynamicObject::DynamicCollision(Object* object, float x, float xMax, float y, float yMax, float z, float zMax)
{
	if (x < object->x + object->width &&
		xMax > object->x &&
		y < object->y + object->height &&
		yMax > object->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DynamicObject::ProcessChange(Map map, int deltaTime)
{
	Object* rightCol = NULL;
	Object*	leftCol = NULL;
	Object* upCol = NULL;
	Object* downCol = NULL;
	std::vector<Object*> objects = map.GetObjects();
	for (int i = 0; i < objects.size(); i++)
	{
		StaticCollision(objects[i], rightCol, leftCol, upCol, downCol);
	}
	if (xv > 0)
	{
		if (rightCol)
		{
			x = rightCol->x -width-0.2f;
			xv = 0;
		}
		else
		{
			x += ((xv / 10)*deltaTime);
		}
	}
	else if (xv < 0)
	{
		if (leftCol)
		{
			x = leftCol->x+leftCol->width + 0.2f;
			xv = 0;
		}
		else
		{
			x += ((xv / 10)*deltaTime);
		}
	}
	if (yv > 0)
	{
		if (upCol) //Sufit
		{
			//y = upCol->y;
			yv = 0;
		}
		else
		{
			if (deltaTime>1000)
			{
				deltaTime = 1000;
			}
			yv -= ((GRAVITY / 100)*deltaTime);
			y += ((yv / 100)*deltaTime);
			
		}

	}
	else
	{
		if (downCol) //Podloga
		{
			//y = downCol->y + downCol->height + 0.1f;
			yv = yv/2;
			canJump = true;
		}
		else
		{
			if (deltaTime>1000)
			{
				deltaTime = 1000;
			}
			y += ((yv / 100)*deltaTime);
			yv -= ((GRAVITY / 100)*deltaTime);
			canJump = false;
		}
	}
	
}


void DynamicObject::DrawBox(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, std::vector<Shader*> shaders, glm::mat4 VP)
{
	GLfloat vertices[] = {
		-0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,
		0.5, 0.5, -0.5,
		-0.5, 0.5, -0.5,
		-0.5, -0.5, 0.5,
		0.5, -0.5, 0.5,
		0.5, 0.5, 0.5,
		-0.5, 0.5, 0.5,
	};
	GLuint vbo_vertices;
	glGenBuffers(1, &vbo_vertices);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLushort elements[] = {
		0, 1, 2, 3,
		4, 5, 6, 7,
		0, 4, 1, 5, 2, 6, 3, 7
	};
	GLuint ibo_elements;
	glGenBuffers(1, &ibo_elements);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



	glm::vec3 size = glm::vec3(xMax - xMin, yMax - yMin, zMax - zMin);
	glm::vec3 center = glm::vec3((xMin + xMax) / 2, (yMin + yMax) / 2, (zMin + zMax) / 2);
	glm::mat4 transform = glm::translate(glm::mat4(1), center)* glm::scale(glm::mat4(1), size);
	Pipeline p;
	p.Position(center);
	p.Scale(size);
	MainShader* shader = dynamic_cast<MainShader*>(shaders[0]); //MainShader
	shader->Enable();
	shader->SetMVP(p.GetMVPTranslation(VP));
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo_vertices);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat), 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_elements);
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_SHORT, 0);
	glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_SHORT, (GLvoid*)(4 * sizeof(GLushort)));
	glDrawElements(GL_LINES, 8, GL_UNSIGNED_SHORT, (GLvoid*)(8 * sizeof(GLushort)));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glDeleteBuffers(1, &vbo_vertices);
	glDeleteBuffers(1, &ibo_elements);
}




