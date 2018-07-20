#pragma once
#include "Material.h"

class Metal : public Material
{
public:
	Metal(const Vector3 &a, const float f);
	~Metal();
	bool scatter(const Ray & ray, const HitRecord &hitRecord, Vector3 & attenuation, Ray & scattered) const;

	Vector3 albedo;
	float fuzziness;
};

