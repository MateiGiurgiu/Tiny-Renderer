#pragma once

#include "Surface.h"

class Sphere : public Surface
{
public:
	Sphere();
	Sphere(const Vector3 position, const float radius);
	~Sphere();

	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) const;

	float radius;
};

