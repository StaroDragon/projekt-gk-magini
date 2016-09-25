#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <vector>
#include "Shader.h"

/**
*Abstrakcyjna klasa obiektu uzywana przez obiekty statyczne jak i dynamiczne.
*/
class Object
{
public:
	float x;
	float y;
	float z;

	float height;
	float width;
	virtual void Render(std::vector<Shader*> shaders, glm::mat4 VP) = 0;
	virtual void ChangePosition(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

};
#endif //OBJECT_H