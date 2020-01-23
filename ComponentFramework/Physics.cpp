#include "Physics.h"
#include <iostream>


void Physics::RigidbodyRotation(PhysicsObject &object, const float deltaTime) {
	//update orientation angle
	object.angle += object.angularVel * deltaTime + 0.5f * object.angularAccel * deltaTime * deltaTime;


	//angular velocity
	object.angularVel += object.angularAccel * deltaTime;
}

void Physics::SimpleNewtonMotion(PhysicsObject& object, const float deltaTime) {
	//update linear velocity
	object.vel += object.accel * deltaTime;

	//update position vectors for x y z axis
	object.pos += object.vel * deltaTime + 0.5f * object.accel * deltaTime * deltaTime;

	
}

bool Physics::PlaneSphereCollision(const PhysicsObject &object, const Plane &p) {
	return false;
}

void Physics::PlaneSphereCollisionResponse(PhysicsObject &object, const Plane &p) {
}

bool Physics::SphereSphereCollision(const PhysicsObject &object1, const PhysicsObject &object2) {
	return false;
}

void Physics::SphereSphereCollisionResponse(PhysicsObject &object1, PhysicsObject &object2) {
}




