#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H
#include "Vector.h"
#include "Sphere.h"

using namespace MATH;

class PhysicsObject {
	friend class Physics;
public:
	PhysicsObject();
	virtual ~PhysicsObject();
	

public:
	/// Untility functions so small they cane be inlined
	inline void setPos(const Vec3 &pos_) { pos = pos_; }
	inline Vec3 getPos() { return pos; }
	inline void setVel(const Vec3 &vel_) { vel = vel_; }
	inline Vec3 getVel() { return vel; }
	inline void setAccel(const Vec3 &accel_) { accel = accel_; }
	inline Vec3 getAccel() { return accel; }
	
	//Apply the force using a = F/m
	inline void applyForce(const Vec3 force) { accel = force / mass;  }
	//apply torque using alpha = T/I
	inline void ApplyTorque(const float torque) { angularAccel = torque / rotationalIntertia; }
	//get the value of our angle
	inline float getAngle() { return angle; }

	//getters and setters for AngularVel and AngularAccel
	inline void setAngularVel(const float& angularVel_) { angularVel = angularVel_; }
	inline float getAngularVel() { return angularVel; }

	inline void setAngularAccel(const float& angularAccel_) { angularVel = angularAccel_; }
	inline float getAngularAccel() { return angularAccel; }

protected:
	Vec3 pos, vel, accel;
	float mass;
	
	float angle;

	float angularVel, angularAccel;

	float rotational;
	float rotationalIntertia;
	Sphere boundingSphere;
};
#endif

