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
	bool m_physics;
	bool m_is_visible;
	void DrawTop(int x, int y, int  z);
	void DrawBottom(int x, int y, int  z);
	void DrawFront(int x, int y, int  z);
	void DrawBack(int x, int y, int  z);
	void DrawLeft(int x, int y, int  z);
	void DrawRight(int x, int y, int  z);
public:
	Block();
	void SetType(int val);
	void Enablephysics(bool val);
	void EnableVisbility(bool val);
	int GetType();
	bool GetPhysics();
	bool GetVisibility();
	void DrawBlock(int type, int bx, int by,int  bz);
};
