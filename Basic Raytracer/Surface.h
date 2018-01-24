#pragma once

#include "Vector3.h"
#include "Ray.h"

struct HitRecord
{
	float t;
	Vector3 p;
	Vector3 normal;
};

class Surface
{
public:
	Vector3 position;
	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) const = 0;
};

