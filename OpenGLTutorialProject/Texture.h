#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include <gl/glew.h>

class Texture
{
public:
	Texture(std::string fileName);

	void Bind(unsigned int unit);

	virtual ~Texture(void);
private:
	Texture(const Texture& other);
	void operator=(const Texture& other);

	GLuint m_texture;
};

#endif
