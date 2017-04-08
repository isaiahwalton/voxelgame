#pragma once

#include <windows.h>
#include <GL/GLU.h>
#include <GL/glut.h>

namespace settings {
	//int Fov;
	int getFOV();
	void setFOV(int fov);
	void setVSync(bool synnc);
}
