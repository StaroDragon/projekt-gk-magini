#ifndef TEXTSHADER_H
#define	TEXTSHADER_H

#include <glm/glm.hpp>
#include "Shader.h"

/**
*Shader odpowiedizalny za wyswietlanie tekstu
*/
class TextShader : public Shader
{
public:
	TextShader();

	virtual bool Init();

	void SetProjection(const glm::mat4& projection);
	void SetText(int mode);
	void SetTextColor(const glm::vec3& color);

private:
	GLuint m_projection;
	GLuint m_text;
	GLuint m_textColor;


};
#endif