#ifndef SPIKES_H
#define	SPIKES_H

#include <vector>
#include "DynamicObjects.h"
#include "Mesh.h"

/**
* Klasa kolcow
*/
class Spikes : public DynamicObject
{
private:
	Mesh* mesh;

public:
	Spikes();
	Spikes(float x, float y, float z);
	~Spikes();
	void Render(std::vector<Shader*> shaders, glm::mat4 VP);

};

#endif