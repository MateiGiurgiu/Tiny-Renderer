#pragma once

#include "Vector3.h"

class Ray
{
public:
	Ray();
	Ray(const Vector3& a, const Vector3& b);
	Ray(const Ray& r);
	~Ray();

	Vector3 Origin() const;
	Vector3 Direction() const;
	Vector3 PointAtParameter(const float t) const;

	Vector3 A, B;
};

