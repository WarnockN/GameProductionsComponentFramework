
#include "Vec3.h"

/* Vec3 Constructor
	Set the vector's x, y, and z components to 0*/
Vec3::Vec3()
{
	x = y = z = 0.0f;
}

/* Vec3 Constructor
	Set the vector's x, y, and z components to the parameters supplied*/
Vec3::Vec3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}

/*	Vec3 overload
	 Overload the + operator to add vectors */
Vec3 Vec3::operator+(const Vec3& v) const
{
	return Vec3(x + v.x, y + v.y, z + v.z);
}

/*	Vec3 overload
	 Overload the - operator to subtract vectors */
Vec3 Vec3::operator-(const Vec3& v) const
{
	return Vec3(x - v.x, y - v.y, z - v.z);
}

/*	Vec3 overload
	 Overload the * operator to multiply vectors */
Vec3 Vec3::operator*(const float s) const
{
	return Vec3(x * s, y * s, z * s);
}

/* Add Member Function
	Adds the vector's x, y, and z components with the supplied vector's x, y, and z components */
void Vec3::Add(Vec3 b)
{
	x += b.x;
	y += b.y;
	z += b.z;
}

/* Subtract Member Function
	Subtracts the vector's x, y, and z components with the parameters supplied */
void Vec3::Subtract(Vec3 b)
{
	x -= b.x;
	y -= b.y;
	z -= b.z;
}

/* ScalarMultiplication Member Function
	Multiplies the vector's x, y, and z components with the scalar supplied */
void Vec3::ScalarMultiplication(float s)
{
	x *= s;
	y *= s;
	z *= s;
}

/* Mag Member Function
	Calculates and returns the vector's magnitude */
float Vec3::Mag()
{
	float x2 = pow(x, 2.0);
	float y2 = pow(y, 2.0);
	float z2 = pow(z, 2.0);
	float magnitude = sqrt(x2 + y2 + z2);
	return magnitude;
}

/* Normalize Member Function
	Normalizes the vector */
void Vec3::Normalize()
{
	float magnitude = Mag();
	x = x / magnitude;
	y = y / magnitude;
	z = z / magnitude;
}

/* Dot Member Function
	Calculates and returns the scalar result for the dot product of the vector and vector supplied */
float Vec3::Dot(Vec3 b)
{
	float x2 = x * b.x;
	float y2 = y * b.y;
	float z2 = z * b.z;
	float dot = x2 + y2 + z2;
	return dot;
}

/* Lerp Member Function
	Calculates the lerp for the vector and vector supplied using unit interval t */
void Vec3::Lerp(Vec3 b, float t)
{
	x = (1 - t) * x + t * b.x;
	y = (1 - t) * y + t * b.y;
	z = (1 - t) * z + t * b.z;
}

/* RotateZ Member Function
	Calculates the rotation for the vector */
void Vec3::RotateZ(float angle)
{
	x = x * cos(angle) - y * sin(angle);
	y = x * sin(angle) + y * cos(angle);
}

void Vec3::Cross(Vec3 otherVec) {

	float _x = x;
	float _y = y;
	float _z = z;

	x = (_y * otherVec.z) - (_z * otherVec.y);
	y = (_z * otherVec.x) - (_x * otherVec.z);
	z = (_x * otherVec.y) - (_y * otherVec.x);
}
