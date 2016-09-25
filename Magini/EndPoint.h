#ifndef ENDPOINT_H
#define	ENDPOINT_H

#include <vector>
#include "DynamicObjects.h"
#include "Mesh.h"

/**
*Klasa punktu koncowego
*/
class EndPoint : public DynamicObject
{
private:
	Mesh* mesh;

public:
	EndPoint();
	EndPoint(float x, float y, float z);
	~EndPoint();
	void Render(std::vector<Shader*> shaders, glm::mat4 VP);

};

#endif
