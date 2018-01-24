#include "stdafx.h"
#include "SurfaceList.h"


SurfaceList::SurfaceList()
{
}

SurfaceList::SurfaceList(Surface** list, const int list_size)
{
	this->list = list;
	this->list_size = list_size;
}


SurfaceList::~SurfaceList()
{
}

bool SurfaceList::Hit(const Ray & ray, float t_min, float t_max, HitRecord & hitRecord) const
{
	HitRecord temp;
	bool hitAnything = false;
	double closest = t_max;

	for (int i = 0; i < list_size; i++)
	{
		if (list[i]->Hit(ray, t_min, float(closest), temp))
		{
			hitAnything = true;
			closest = temp.t;
			hitRecord = temp;
		}
	}
	return hitAnything;
}
