#include "Player.h"

void Player::GenerateMesh()
{

}

void Player::SetPos(float x, float y, float z)
{
	Player::x = x;
	Player::y = y;
	Player::z = z;
}

void Player::SetAngle(float anglex, float angley, float anglez)
{
	Player::angleX = anglex;
	Player::angleY = angley;
	Player::angleZ = anglez;
}

float Player::Jump(float Hight)
{
	float HightRemaining = Hight;
	Player::y += Player::JumpVel;
	if(Player::y != HightRemaining){
		return HightRemaining - Player::JumpVel;
	}else{
		return 0;
	}
}

void Player::PlaceBlock(int x, int y, int z, types type)
{
	chunkmanager.SetBlock(x, y, z, type);
}

void Player::BreakBlock(int x, int y, int z)
{
	chunkmanager.SetBlock(x, y, z, types::air);
}

void Player::Update()
{
	if (is_flying)
	{
		//TODO MAKE THIS WORK!
	}
	glRotatef(-angleY, 0, 1, 0);
	glRotatef(-angleX, 1, 0, 0);
	glRotatef(-angleZ, 0, 0, 1);
	glTranslatef(-x, -y, -z);
}
