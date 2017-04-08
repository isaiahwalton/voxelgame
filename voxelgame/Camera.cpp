#include "Camera.h"



float Camera::DegreesToRadians(float radians) 
{
	float degrees = ((radians * 3.14159265358979323846) / 180);
	return degrees;
}

Camera::Camera()
{
}

pos Camera::MoveForward(double distance, double angle, int time)
{
	pos amountmoved;
	amountmoved.x = time * (distance * sin(DegreesToRadians(angle)));
	amountmoved.z = time * (distance * cos(DegreesToRadians(angle)));
	return amountmoved;
}
pos Camera::MoveBackward(double distance, double angle, int time)
{
	pos amountmoved;
	amountmoved.x = time * (distance * sin(DegreesToRadians(angle + 180)));
	amountmoved.z = time * (distance * cos(DegreesToRadians(angle + 180)));
	return amountmoved;
}
pos Camera::StrafLeft(double distance, double angle, int time)
{
	pos amountmoved;
	amountmoved.x = time * (distance * sin(DegreesToRadians(angle + 270)));
	amountmoved.z = time * (distance * cos(DegreesToRadians(angle + 270)));
	return amountmoved;
}
pos Camera::StrafRight(double distance, double angle, int time)
{
	pos amountmoved;
	amountmoved.x = time * (distance * sin(DegreesToRadians(angle + 90)));
	amountmoved.z = time * (distance * cos(DegreesToRadians(angle + 90)));
	return amountmoved;
}
