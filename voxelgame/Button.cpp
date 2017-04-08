#include "Button.h"


Button::Button(int x, int y, int hight, int width)
{
	ButtonX = x;
	ButtonY = y;
	Hight = hight;
	Width = width;
}

void Button::DrawButton() 
{
	ButtonTex.Bind();
	glBegin(GL_QUADS);
	glVertex2d(ButtonX + (Width / 2), ButtonY + (Hight / 2));
	glTexCoord2d(0, 1);
	glVertex2d(ButtonX + (Width / 2), ButtonY - (Hight / 2));
	glTexCoord2d(1, 1);
	glVertex2d(ButtonX - (Width / 2), ButtonY - (Hight / 2));
	glTexCoord2d(1, 0);
	glVertex2d(ButtonX - (Width / 2), ButtonY + (Hight / 2));
	glTexCoord2d(0, 0);
	glColor3f(1, 1, 1);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}

bool Button::IsPressed(HWND hwnd) 
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(hwnd, &p);
	if ((p.y <= (ButtonY + (Hight / 2))
		&& p.y >= (ButtonY - (Hight / 2))
		&& p.x <= (ButtonX + (Width / 2))
		&& p.x >= (ButtonX - (Width / 2))) && GetAsyncKeyState(VK_LBUTTON))
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