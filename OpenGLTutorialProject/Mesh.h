#pragma once

#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <gl/glew.h>
#include <string>
#include "Obj_Loader.h"

struct Vertex
{
public:
	Vertex(const glm::vec3 pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0,0,0))
	{
		this->pos = pos;
		this->texCoord = texCoord;
		this->normal = normal;
	}

	glm::vec3* GetPos() { return &pos; }
	glm::vec2* GetTexCoord() { return &texCoord; }
	glm::vec3* GetNormal() { return &normal; }

private:
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 normal;
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	Mesh(const std::string& fileName);

	void Draw();

	virtual ~Mesh(void);
private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);
	void InitMesh(const IndexedModel& model);

	enum 
	{
		POSITION_VB,
		TEXCOORD_VB,
		INDEX_VB,
		NORMAL_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_numIndices;
};

#endif

