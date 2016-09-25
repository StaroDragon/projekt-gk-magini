#ifndef PIPELINE_H
#define	PIPELINE_H
#include <glm/glm.hpp>
#include "Camera.h"
#include "Perspective.h"


/**
*Klasa odpowiedzialna za odpowiednia kolejnosc przeksztalcen afinicznych
*/
class Pipeline
{
private:
	glm::vec3 m_scale; //! Skala
	glm::vec3 m_rotation_axis; //! Os obrotu
	float m_rotation_degrees; //! Stopien obrotu
	glm::vec3 m_position; //!Pozycja
	glm::mat4 m_modelMatrix; //!Macierz modelu

	glm::mat4 m_perspectiveMatrix; //!Macierz perspektywy
	PerspectiveInfo m_perspectiveInfo; //!Informacje o perspektywie

	glm::mat4 m_viewMatrix; //!Macierz widoku
	Camera m_cameraInfo; //Kamera

	glm::mat4 m_pvMatrix; //Macierz perspektywy i widoku.


public:
	Pipeline()
	{
		m_scale = glm::vec3(1.0f);
		m_rotation_axis = glm::vec3(1.0f);
		m_rotation_degrees = 0.0f;
		m_position = glm::vec3(0.0f);
	}

	void Scale(float scale)
	{
		m_scale = glm::vec3(scale);
	}

	void Scale(float x, float y, float z)
	{
		m_scale = glm::vec3(x, y, z);
	}

	void Scale(glm::vec3 scale)
	{
		m_scale = scale;
	}

	void Rotate(float degrees, glm::vec3 rotation_axis)
	{
		m_rotation_degrees = degrees;
		m_rotation_axis = rotation_axis;
	}
	void Rotate(float degrees, float x, float y, float z)
	{
		m_rotation_degrees = degrees;
		m_rotation_axis = glm::vec3(x, y, z);
	}

	void Position(glm::vec3 position)
	{
		m_position = position;
	}
	
	void Position(float x, float y, float z)
	{
		m_position = glm::vec3(x, y, z);
	}

	void SetPerspective(float FOV, float width, float height, float zNear, float zFar)
	{
		m_perspectiveInfo = PerspectiveInfo(FOV,width,height,zNear,zFar);
	}

	void SetPerspective(PerspectiveInfo perspective)
	{
		m_perspectiveInfo = perspective;
	}

	void SetCamera(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
	{
		m_cameraInfo = Camera(pos, target, up);
	}

	void SetCamera(Camera camera)
	{
		m_cameraInfo = camera;
	}

	void SetVP(glm::mat4 VP)
	{
		m_pvMatrix = VP;
	}

	glm::mat4 GetModelTranslation();
	glm::mat4 GetPerspectiveTranslation();
	glm::mat4 GetViewTranslation();
	glm::mat4 GetVPTranslation();
	glm::mat4 GetMVPTranslation();
	glm::mat4 GetMVPTranslation(glm::mat4 VP);

};
#endif