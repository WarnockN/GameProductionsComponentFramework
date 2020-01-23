#include "Ray.h"

Ray::Ray(Vec3 start_, Vec3 dir_) {
	start = start_;
	dir = dir_;
}

Vec3 Ray::currentPosition(float t) {
	//get currentPos and multiplt my t
	Vec3 currentPos = (start + dir) * t;

	return currentPos;
}
