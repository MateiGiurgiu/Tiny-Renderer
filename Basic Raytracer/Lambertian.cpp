#include "stdafx.h"
#include "Lambertian.h"
//#include "Basic Raytracer.cpp"

Vector3 RandomInUnitSphere();

Lambertian::Lambertian(const Vector3 & a)
{
	albedo = a;
}

Lambertian::~Lambertian()
{
}

bool Lambertian::scatter(const Ray & ray, const HitRecord &hitRecord, Vector3 & attenuation, Ray & scattered) const
{
	Vector3 target = hitRecord.p + hitRecord.normal + RandomInUnitSphere();
	scattered = Ray(hitRecord.p, target - hitRecord.p);
	attenuation = albedo; 
	return true;
}
