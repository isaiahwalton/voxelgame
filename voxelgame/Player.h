#pragma once

#include "GlobalVars.h"
#include <Windows.h>
#include <GL/GL.h>
#include <GL/glut.h>

struct Slot {
	int id;
	int amount;
};

class Player {
private:
	Slot slots[9][2];
	Slot hotbar[9];
	bool is_flying;
	float x;
	float y;
	float z;
	float angleY;
	float angleX;
	float angleZ;
	float speed;
	const float JumpVel = 0.05f;
public:
	void GenerateMesh();
	void SetPos(float x, float y, float z);
	void SetAngle(float anglex, float angley, float anglez);
	float Jump(float Hight);
	void PlaceBlock(int x, int y, int z, types type);
	void BreakBlock(int x, int y, int z);
	void Update();
};