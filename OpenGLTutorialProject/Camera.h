#pragma once

#ifndef CAMERA_H_INSTANCE
#define CAMERA_H_INSTANCE

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
	{
		this->m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		this->m_position = pos;

		this->m_forward = glm::vec3(0,0,1);
		this->m_up = glm::vec3(0,1,0);
	}

	inline glm::mat4 GetViewProjection() const
	{
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}

protected:
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
};

#endif