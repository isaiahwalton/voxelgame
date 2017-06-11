#include "Button.h"


Button::Button(int x, int y, int height, int width)
{
	ButtonX = x;
	ButtonY = y;
	Height = height;
	Width = width;
}

void Button::DrawButton() 
{
	ButtonTex.Bind();
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex2d(ButtonX + (Width / 2), ButtonY + (Height / 2));
	//glTexCoord2d(0, 1);
	glTexCoord2d(1, 0);
	glVertex2d(ButtonX + (Width / 2), ButtonY - (Height / 2));
	//glTexCoord2d(1, 1);
	glTexCoord2d(0, 0);
	glVertex2d(ButtonX - (Width / 2), ButtonY - (Height / 2));
	//glTexCoord2d(1, 0);
	glTexCoord2d(0, 1);
	glVertex2d(ButtonX - (Width / 2), ButtonY + (Height / 2));
	//glTexCoord2d(0, 0);
	glTexCoord2d(1, 1);
	glColor3f(1, 1, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Button::IsPressed(HWND hwnd) 
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hwnd, &p);
	if ((p.y <= (ButtonY + (Height / 2))
		&& p.y >= (ButtonY - (Height / 2))
		&& p.x <= (ButtonX + (Width / 2))
		&& p.x >= (ButtonX - (Width / 2))) && GetAsyncKeyState(VK_LBUTTON) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Button::LoadButtonTex(const char* texture) {
	ButtonTex.Load(texture);
}