#include "Vec4.h"
#include <math.h>

Vec4::Vec4() {
	x = y = z = 0.0f;
	w = 1.0f;
}

Vec4::~Vec4() {}

Vec4::Vec4(float x_, float y_, float z_, float w_) {
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}

float Vec4::Mag()
{
	// do math here
	float x2 = pow(x, 2.0);
	float y2 = pow(y, 2.0);
	float z2 = pow(z, 2.0);
	float w2 = pow(w, 2.0);

	float mag = sqrt(x2 + y2 + z2 + w2);
	return mag;
}

float Vec4::Dot(Vec4 otherVec)
{
	//do math here
	float x2 = x * otherVec.x;
	float y2 = y * otherVec.y;
	float z2 = z * otherVec.z;
	float w2 = w * otherVec.w;

	float dot = x2 + y2 + z2 + w2;
	return dot;
}

void Vec4::Normalize() {
	float magnitude = Mag();
	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
	w = w / magnitude;
}
