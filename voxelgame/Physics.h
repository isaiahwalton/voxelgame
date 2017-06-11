#pragma once

#include "btBulletDynamicsCommon.h"
#include <vector>

enum CollisionTypes
{
	box,
	sphere,
	mesh
};

class Physics
{
private:
	
	btDefaultCollisionConfiguration* collisionConfiguration;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
	
public:
	Physics(double gravity = -9.81);
	~Physics();
	void Update(double time);
	void AddObject(btScalar size, btVector3 &position, btScalar mass, btVector3 &localInertia, CollisionTypes CollisionType);
};

