#pragma once

#include <math.h>

struct pos {
	double x;
	double z;
	double y;
};

class Camera
{
private:
	float DegreesToRadians(float radians);
public:
	Camera(); 
	pos MoveForward(double distance, double angle, int time);
	pos MoveBackward(double distance, double angle, int time);
	pos StrafLeft(double distance, double angle, int time);
	pos StrafRight(double distance, double angle, int time);
};

