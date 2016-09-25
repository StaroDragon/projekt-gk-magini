#include "MainShader.h"


MainShader::MainShader()
{

}

bool MainShader::Init()
{
	m_shaderProg = glCreateProgram();

	if (m_shaderProg == 0) {
		fprintf(stderr, "Error creating shader program\n");
		return false;
	}

	if (!AddShader(GL_VERTEX_SHADER, "shader.vs")) {
		return false;
	}

	if (!AddShader(GL_FRAGMENT_SHADER, "shader.fs")) {
		return false;
	}

	if (!Finalize()) {
		return false;
	}

	m_MVPLocation = GetUniformLocation("gMVP");
	m_samplerLocation = GetUniformLocation("gSampler");

	if (m_MVPLocation == 0xFFFFFFFF ||
		m_samplerLocation == 0xFFFFFFFF)
	{
		return false;
	}

	return true;
}

void MainShader::SetMVP(const glm::mat4& mvp)
{
	glUniformMatrix4fv(m_MVPLocation, 1, GL_FALSE, &mvp[0][0]);
}


void MainShader::SetTextureUnit(unsigned int TextureUnit)
{
	glUniform1i(m_samplerLocation, TextureUnit);
}