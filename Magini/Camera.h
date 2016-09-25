#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

#define CAMERA_UP 1
#define CAMERA_DOWN 2
#define CAMERA_RIGHT 3
#define CAMERA_LEFT 4
/**
Klasa odpowiedzialna za kamere
**/
class Camera
{

public:
	Camera()
	{

	}
	Camera(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
	{
		m_pos = pos;
		m_target = target;
		m_up = up;
	}

	glm::vec3 GetPos()
	{
		return m_pos;
	}
	glm::vec3 GetTarget()
	{
		return m_target;
	}
	glm::vec3 GetUp()
	{
		return m_up;
	}

	void MoveCamera(int direction, float rate);

	void SetCameraPosition(glm::vec3 pos)
	{
		m_pos = pos;
	}



private:
	glm::vec3 m_pos; //!Pozycja kamery
	glm::vec3 m_target;//! Gdzie jest skierowana kamera
	glm::vec3 m_up; //! Wskaznik "gory"
};
#endif