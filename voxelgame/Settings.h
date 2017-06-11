#pragma once

#include <windows.h>
#include <GL/GLU.h>
#include <GL/glut.h>
#include <iostream>

enum Inputs{
	MoveForward,
	MoveBackward,
	StraffLeft,
	StraffRight,
	BreakBlock,
	PlaceBLock,
	Sprint,
	Jump,
	Slot0,
	Slot1,
	Slot2,
	Slot3,
	Slot4,
	Slot5,
	Slot6,
	Slot7,
	Slot8,
	Slot9
};

class Settings {
private:
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD NumInputs = 0;
	DWORD InputsRead = 0;

	INPUT_RECORD irInput;

	int MoveForwardKey = 'W';
	int MoveBackwardKey = 'S';
	int StraffLeftKey = 'A';
	int StraffRightKey = 'D';
	int BreakBlockKey = VK_RBUTTON;
	int PlaceBLockKey = VK_LBUTTON;
	int SprintKey = VK_LCONTROL;
	int JumpKey = VK_SPACE;
	int Slot0Key = '1';
	int Slot1Key = '2';
	int Slot2Key = '3';
	int Slot3Key = '4';
	int Slot4Key = '5';
	int Slot5Key = '6';
	int Slot6Key = '7';
	int Slot7Key = '8';
	int Slot8Key = '9';
	int Slot9Key = '0';
	int Fov = 70;
public:
	int GetFOV();
	int RenderDistance = 15;
	void SetFOV(int fov);
	void SetVSync(bool synnc);
	void SetRenderDistance(int dist);//in chunks
	int GetRenderDistance(int dist);
	int GetCurrentKeyPressed();
	void SetKey(Inputs input, int key);
};