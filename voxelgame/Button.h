#pragma once

#include <Windows.h>
#include <GL\GLU.h>
#include <GL\glut.h>
#include "Texture.h"
#include <iostream>

class Button
{
private:
	int ButtonX;
	int ButtonY;
	Texture ButtonTex;
	int Hight;
	int	Width;
	char* TextureName;
public:
	Button(int x, int y, int hight, int width);
	void DrawButton();
	bool IsPressed(HWND hwnd);
	void LoadButtonTex(const char* texture);
};

