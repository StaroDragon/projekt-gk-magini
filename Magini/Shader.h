#ifndef SHADER_H
#define	SHADER_H

#include <list>
#include <GL/glew.h>
#include <glm/glm.hpp>

#define INVALID_UNIFORM_LOCATION 0xffffffff

/**
*Klasa abstrakcyjna majaca za zadanie zapewnienie szkieletu dla wyspecjalizowanych shaderow
*/
class Shader
{
public:

	/**
	*Konstruktor
	*/
	Shader();

	/**
	*Wirtualny destruktor
	*/
	virtual ~Shader();

	/**
	*Wirutalna metoda, ktora jest przeznaczona do inicjalizowania konkretnych implementacji shaderow.
	*/
	virtual bool Init();

	/**
	*Metoda do aktywacji danego shadera
	*/
	void Enable();

protected:

	/**
	*Metoda dodajaca shadery do programu
	*/
	bool AddShader(GLenum ShaderType, const char* pFilename);

	/**
	*Metoda finalizujaca shadery. Odpowiada za linkowanie i walidacje.
	*/
	bool Finalize();

	GLint GetUniformLocation(const char* pUniformName);

	GLint GetProgramParam(GLint param);

	GLuint m_shaderProg;

private:

	typedef std::list<GLuint> ShaderObjList;
	ShaderObjList m_shaderObjList;
};

#endif