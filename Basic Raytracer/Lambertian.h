#pragma once
#include "Vector3.h"
#include "Material.h"

class Lambertian : public Material
{
public:
	Lambertian(const Vector3 &a);
	~Lambertian();

	bool scatter(const Ray & ray, const HitRecord &hitRecord, Vector3 & attenuation, Ray & scattered) const;

	Vector3 albedo;
};

