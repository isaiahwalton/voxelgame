#pragma once

class Player {
private:
	double x;
	double y;
	double z;
	double angleY;
	double angleX;
	double speed;
	const float JumpVal = 0.05f;
public:
	void SetPos(double x, double y, double z);
	void SetAngle(double anglex, double angley);
	double Jump(double Hight);
	void PlaceBlock(int x, int y, int z, int type);
	void BreakBlock(int x, int y, int z);
};