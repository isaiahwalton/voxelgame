#include "Player.h"

void Player::SetPos(double x, double y, double z)
{
	Player::x = x;
	Player::y = y;
	Player::z = z;
}

void Player::SetAngle(double anglex, double angley)
{
	Player::angleX = anglex;
	Player::angleY = angley;
}

double Player::Jump(double Hight)
{
	double HightRemaining = Hight;
	Player::y += Player::JumpVal;
	if(Player::y != HightRemaining){
		return HightRemaining - Player::JumpVal;
	}else{
		return 0;
	}
}

void Player::PlaceBlock(int x, int y, int z, int type)
{
	//SetBlock(x, y, z, type);
}

void Player::BreakBlock(int x, int y, int z)
{
	//SetBlock(x, y, z, air);
}
