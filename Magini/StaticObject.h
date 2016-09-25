#ifndef STATICOBJ_H
#define	STATICOBJ_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include "GameDefs.h"
#include "Object.h"
#include "Texture.h"
#include "MainShader.h"
#include "Vertex.h"


/**
*Klasa dla klocka budulcowego, ktory jest jedynym wystepujacym obiektem statycznym.
*/
class BasicTile : public Object
{
protected:
	//!Vertex buffer
	GLuint VB;
	//!Index buffer
	GLuint IB;
	//!Tekstura
	Texture* texture;
public:
	BasicTile(float x, float y, float z);
	virtual void Render(std::vector<Shader*> shaders, glm::mat4 VP);
};

#endif
