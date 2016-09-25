#include <iostream>
#include "Texture.h"

bool Texture::Load()
{
	m_image = SOIL_load_image(m_fileName.c_str(), &m_texWidth, &m_texHeight, 0, SOIL_LOAD_RGBA);
	if (m_image == NULL)
	{
		return false;
	}
	glGenTextures(1, &m_textureObj);
	glBindTexture(m_textureTarget, m_textureObj);
	glTexImage2D(m_textureTarget, 0, GL_RGBA, m_texWidth, m_texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameterf(m_textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(m_textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SOIL_free_image_data(m_image);
	glBindTexture(m_textureTarget, 0);

	return true;
}

void Texture::Bind(GLenum TextureUnit)
{
	glActiveTexture(TextureUnit);
	glBindTexture(m_textureTarget, m_textureObj);
}