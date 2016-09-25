#ifndef TEXTRENDERER_H
#define TEXTRENDERER_H

#include <map>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "TextShader.h"



struct Character {
	GLuint TextureID;   
	glm::ivec2 Size;    
	glm::ivec2 Bearing; 
	GLuint Advance;     
};

/**
*Klasa odpowiedzialna za wyswietlanie tekstu
*/
class TextRenderer
{
public:
	std::map<GLchar, Character> Characters; //!Mapa znakow
	TextShader shader;//!Shader tekstu
	/**
	*Konstruktor
	*/
	TextRenderer(GLuint width, GLuint height);
	/**
	*Metoda odpowiedzialna za ladowanie czcionki
	*/
	void Load(std::string font, GLuint fontSize);
	/**
	*Metoda odpowiedzialna za renderowanie tekstu
	*/
	void RenderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color = glm::vec3(1.0f));
private:
	GLuint VAO, VBO;
	glm::mat4 projection;
	GLuint mode;
};
#endif