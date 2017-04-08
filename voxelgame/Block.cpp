#include "Block.h"

Texture BlockTexture;
Texture Dirt;
Texture Stone;
Texture GrassSide;
Texture GrassTop;
Texture Bedrock;
Texture Diamond_ore;
Texture Wood_planks;
Texture Wood_side;
Texture Wood_Top;
Texture Cobblestone;
void loadtextures() {
	Dirt.Load("textures\\dirt.bmp");
	Stone.Load("textures\\stone.bmp");
	GrassSide.Load("textures\\grassblockside.bmp");
	GrassTop.Load("textures\\grassblockTop.bmp");
	Bedrock.Load("textures\\bedrock.bmp");
	Diamond_ore.Load("textures\\diamond_ore.bmp");
	Wood_planks.Load("textures\\wood_planks.bmp");
	Wood_side.Load("textures\\wood_side.bmp");
	Wood_Top.Load("textures\\wood_Top.bmp");
	Cobblestone.Load("textures\\cobblestone.bmp");
}

Block::Block()
{
	m_type = types::air;
	m_physics = false;
	m_is_visible = true;
}

void Block::DrawTop(int x, int y, int  z)
{
	glBegin(GL_QUADS);
	glVertex3f(x, y + 1, z);
	glTexCoord2f(0, 0);
	glVertex3f(x + 1, y + 1, z);
	glTexCoord2f(0, 1);
	glVertex3f(x + 1, y + 1, z + 1);
	glTexCoord2f(1, 1);
	glVertex3f(x, y + 1, z + 1);
	glTexCoord2f(1, 0);
	glEnd();
}
void Block::DrawBottom(int x, int y, int  z)
{
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glTexCoord2f(0, 0);
	glVertex3f(x + 1, y, z);
	glTexCoord2f(0, 1);
	glVertex3f(x + 1, y, z + 1);
	glTexCoord2f(1, 1);
	glVertex3f(x, y, z + 1);
	glTexCoord2f(1, 0);
	glEnd();
}
void Block::DrawFront(int x, int y, int  z)
{
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glTexCoord2f(0, 0);
	glVertex3f(x + 1, y, z);
	glTexCoord2f(0, 1);
	glVertex3f(x + 1, y + 1, z);
	glTexCoord2f(1, 1);
	glVertex3f(x, y + 1, z);
	glTexCoord2f(1, 0);
	glEnd();
}
void Block::DrawBack(int x, int y, int  z)
{
	glBegin(GL_QUADS);
	glVertex3f(x, y, z + 1);
	glTexCoord2f(0, 0);
	glVertex3f(x + 1, y, z + 1);
	glTexCoord2f(0, 1);
	glVertex3f(x + 1, y, z + 1);
	glTexCoord2f(1, 1);
	glVertex3f(x, y, z + 1);
	glTexCoord2f(1, 0);
	glEnd();
}
void Block::DrawLeft(int x, int y, int  z)
{
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glTexCoord2f(0, 0);
	glVertex3f(x, y, z + 1);
	glTexCoord2f(0, 1);
	glVertex3f(x, y + 1, z + 1);
	glTexCoord2f(1, 1);
	glVertex3f(x, y + 1, z);
	glTexCoord2f(1, 0);
	glEnd();
}
void Block::DrawRight(int x, int y, int  z)
{
	glBegin(GL_QUADS);
	glVertex3f(x + 1, y, z);
	glTexCoord2f(0, 0);
	glVertex3f(x + 1, y, z + 1);
	glTexCoord2f(0, 1);
	glVertex3f(x + 1, y + 1, z + 1);
	glTexCoord2f(1, 1);
	glVertex3f(x + 1, y + 1, z);
	glTexCoord2f(1, 0);
	glEnd();
}

void Block::SetType(int val)
{
	m_type = val;
}

void Block::Enablephysics(bool val)
{
	m_physics = val;
}

void Block::EnableVisbility(bool val)
{
	m_is_visible = val;
}

int Block::GetType()
{
	return m_type;
}

bool Block::GetPhysics()
{
	return m_physics;
}

bool Block::GetVisibility()
{
	return m_is_visible;
}

void Block::DrawBlock(int type, int bx, int by,int  bz)
{
	float x = (float)bx;
	float y = (float)by;
	float z = (float)bz;

	switch (type) {
	case 1:
		Dirt.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 2:
		GrassTop.Bind();
		DrawTop(x, y, z);
		Dirt.Bind();
		DrawBottom(x, y, z);
		GrassSide.Bind();
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 3:
		Stone.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 4:
		Wood_Top.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		Wood_side.Bind();
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 5:
		Bedrock.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 6:
		Cobblestone.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 7:
		Wood_planks.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 8:
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 9:
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	case 10:
		Diamond_ore.Bind();
		DrawTop(x, y, z);
		DrawBottom(x, y, z);
		DrawFront(x, y, z);
		DrawBack(x, y, z);
		DrawLeft(x, y, z);
		DrawRight(x, y, z);
		break;
	}
}
