#pragma once

#include "Surface.h"
class SurfaceList
{
public:
	SurfaceList();
	SurfaceList(Surface** list, const int list_size);
	~SurfaceList();

	virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) const;

	Surface** list;
	int list_size;
};

