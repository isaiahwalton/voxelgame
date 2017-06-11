#pragma once

#include <windows.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include "Texture.h"

enum types{
	air,
	bedrock,
	dirtblock,
	grassblock,
	stoneblock
};

class Block {
private:
	int m_type;
public:
	Block();
	void SetType(int val);
	int GetType();
};
