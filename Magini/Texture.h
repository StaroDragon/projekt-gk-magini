#ifndef TEXTURE_H
#define	TEXTURE_H

#include <string>
#include <GL/glew.h>
//#include <ImageMagick/Magick++.h>
#include <SOIL/SOIL.h>


/**
*Klasa przechowujaca i ladujaca tekstury
*/
class Texture
{
private:
	std::string m_fileName;
	GLenum m_textureTarget;
	GLuint m_textureObj;
	int m_texWidth;
	int m_texHeight;
	unsigned char* m_image;


public:

	Texture(GLenum TextureTarget, const std::string& FileName)
	{
		m_textureTarget = TextureTarget;
		m_fileName = FileName;
	}

	bool Load();
	void Bind(GLenum TextureUnit);
};
#endif


