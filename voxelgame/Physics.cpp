#include "Physics.h"


Physics::Physics(double gravity)
{
	//btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	//btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
	//btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();
	//btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
	//btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	//dynamicsWorld->setGravity(btVector3(0, gravity, 0));
}

Physics::~Physics()
{

}

void Physics::AddObject(bool dynamic/*bunches of parameters*/)
{

}
