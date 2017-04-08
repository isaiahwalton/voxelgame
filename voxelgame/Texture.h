#pragma once

#include <windows.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <SDL.h>

class Texture
{
private:
	unsigned int textureID;
public:

	unsigned int Load(const char * filename);
	void Bind();
};

