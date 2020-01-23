#include "PhysicsObject.h"

PhysicsObject::PhysicsObject() :pos(0.0f), vel(0.0f), accel(0.0f), mass(1.0f), boundingSphere(0.0f), rotationalIntertia(1.0f), angularAccel(0.0f), angularVel(0.0f), angle(0.0f){

}


PhysicsObject::~PhysicsObject(){

}

