#pragma once
#include "Surface.h"

class Material
{
	public:
		virtual bool scatter(const Ray &ray, const HitRecord &hitRecord, Vector3 &attenuation, Ray &scattered) const = 0;
};

