#include "Camera.h"

void Camera::MoveCamera(int direction, float rate)
{
	switch (direction)
	{
	case CAMERA_UP:
		m_pos += rate*m_target;
		break;
	case CAMERA_DOWN:
		m_pos -= rate*m_target;
		break;
	case CAMERA_RIGHT:
		m_pos += glm::normalize(glm::cross(m_target, m_up))*rate;
		break;
	case CAMERA_LEFT:
		m_pos -= glm::normalize(glm::cross(m_target, m_up))*rate;
		break;
	default:
		break;
	}
}



