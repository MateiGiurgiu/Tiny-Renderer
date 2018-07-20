#include "stdafx.h"
#include "Metal.h"
#include "Vector3.h"

Vector3 RandomInUnitSphere();

Metal::Metal(const Vector3 &a, const float f)
{
	albedo = a;
	fuzziness = f;
}


Metal::~Metal()
{
}

bool Metal::scatter(const Ray & ray, const HitRecord & hitRecord, Vector3 & attenuation, Ray & scattered) const
{
	Vector3 reflected = Reflect(Normalize(ray.Direction()), hitRecord.normal);
	scattered = Ray(hitRecord.p, reflected + fuzziness * RandomInUnitSphere());
	attenuation = albedo;
	return (Dot(scattered.Direction(), hitRecord.normal) > 0);
}
