#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

using namespace std;

class Vec3
{
public:
	Vec3();
	Vec3(float x_, float y_, float z_);

	Vec3 operator + (const Vec3& v) const;

	Vec3 operator - (const Vec3& v) const;

	Vec3 operator * (const float s) const;

	void Add(Vec3 b);

	void Subtract(Vec3 b);

	void ScalarMultiplication(float s);

	float Mag();

	void Normalize();

	float Dot(Vec3 b);

	void Lerp(Vec3 b, float t);

	void RotateZ(float angle);

	void Cross(Vec3 otherVec);

	float x;
	float y;
	float z;
};

#endif
