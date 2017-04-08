#pragma once

#include "btBulletDynamicsCommon.h"

enum CollisionTypes
{
	box,
	sphere,
	mesh
};

class Physics
{
private:
	//btAlignedObjectArray<btCollisionShape*> collisionShapes;
public:
	Physics(double gravity);
	~Physics();
	void AddObject(bool dynamic/*bunches of parameters*/);
};

