#pragma once

#include <windows.h>
#include <string>
#include <GL/glu.h>
#include <GL/glut.h>
#include <sstream>

struct dim {
	int	width;
	int hight;
};

enum updown {
	up,
	down
};

class Hud {
private:
	std::string double_to_string(double val);
	void DisplayText(int x, int y, std::string text , void* font);
public:
	void DisplayValue(std::string a, double val, double x, double y);
	void Enable2D(bool enable);
	void DisplayBar(POINT center, updown UpDown, dim size, double val);
};