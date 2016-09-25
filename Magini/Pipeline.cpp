#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Pipeline.h"

glm::mat4 Pipeline::GetModelTranslation()
{
	glm::mat4 rotationMatrix, scaleMatrix, translateMatrix;

	scaleMatrix = glm::scale(glm::mat4(),this->m_scale);
	rotationMatrix = glm::rotate(glm::mat4(),this->m_rotation_degrees, this->m_rotation_axis);
	translateMatrix = glm::translate(glm::mat4(),this->m_position);
	m_modelMatrix = translateMatrix*rotationMatrix*scaleMatrix;
	return m_modelMatrix;
}

glm::mat4 Pipeline::GetPerspectiveTranslation()
{
	glm::mat4 perspective;
	perspective = glm::perspective(glm::radians(m_perspectiveInfo.FOV), (float)m_perspectiveInfo.width / (float)m_perspectiveInfo.height, m_perspectiveInfo.zNear, m_perspectiveInfo.zFar);
	m_perspectiveMatrix = perspective;
	return perspective;
}

glm::mat4 Pipeline::GetViewTranslation()
{
	glm::mat4 view;
	view = glm::lookAt(m_cameraInfo.GetPos(), m_cameraInfo.GetTarget()+m_cameraInfo.GetPos(), m_cameraInfo.GetUp());
	m_viewMatrix = view;
	return view;
}

glm::mat4 Pipeline::GetMVPTranslation()
{
	glm::mat4 test;
	GetModelTranslation();
	GetPerspectiveTranslation();
	GetViewTranslation();
	test = m_perspectiveMatrix*m_viewMatrix*m_modelMatrix;
	return test;
}

glm::mat4 Pipeline::GetMVPTranslation(glm::mat4 VP)
{
	glm::mat4 mvp;
	GetModelTranslation();
	mvp = VP*m_modelMatrix;
	return mvp;
}

glm::mat4 Pipeline::GetVPTranslation()
{
	glm::mat4 VP;
	GetPerspectiveTranslation();
	GetViewTranslation();
	VP = m_perspectiveMatrix*m_viewMatrix;
	return VP;
}