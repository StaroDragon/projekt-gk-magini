#ifndef MAINSHADER_H
#define	MAINSHADER_H

#include <glm/glm.hpp>
#include "Shader.h"

/**
*Klasa definiujaca glowny shader uzywany w programie
*/
class MainShader : public Shader
{
public:

	MainShader();

	virtual bool Init();


	void SetMVP(const glm::mat4& mvp);
	void SetTextureUnit(unsigned int TextureUnit);

private:

	GLuint m_MVPLocation;
	GLuint m_samplerLocation;
};

#endif