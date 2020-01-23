#ifndef VEC4_H
#define VEC4_H

class Vec4 {
public:
	float x, y, z, w;

	Vec4();
	~Vec4();

	Vec4(float x_, float y_, float z_, float w_);

	float Mag();

	float Dot(Vec4 otherVec);

	void Normalize();
};

#endif
