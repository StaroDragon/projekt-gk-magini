#include "TextShader.h"

TextShader::TextShader()
{

}

bool TextShader::Init()
{
	m_shaderProg = glCreateProgram();

	if (m_shaderProg == 0) {
		fprintf(stderr, "Error creating shader program\n");
		return false;
	}

	if (!AddShader(GL_VERTEX_SHADER, "text_shader.vs")) {
		return false;
	}

	if (!AddShader(GL_FRAGMENT_SHADER, "text_shader.fs")) {
		return false;
	}

	if (!Finalize()) {
		return false;
	}


	m_projection = GetUniformLocation("projection");
	m_text = GetUniformLocation("text");
	m_textColor = GetUniformLocation("textColor");

	if (m_projection == 0xFFFFFFFF ||
		m_text == 0xFFFFFFFF ||
		m_textColor == 0xFFFFFFFF)
	{
		return false;
	}

	return true;
}

void TextShader::SetProjection(const glm::mat4& projection)
{
	glUniformMatrix4fv(m_projection, 1, GL_FALSE, &projection[0][0]);
}

void TextShader::SetText(int mode)
{
	glUniform1i(m_text, mode);
}

void TextShader::SetTextColor(const glm::vec3& color)
{
	glUniform3fv(m_textColor, 1, &color[0]);
}