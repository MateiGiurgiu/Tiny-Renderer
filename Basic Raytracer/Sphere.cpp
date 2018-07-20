#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere()
{
}

Sphere::Sphere(const Vector3 position, const float radius, Material * material)
{
	this->position = position;
	this->radius = radius;
	this->material = material;
}


Sphere::~Sphere()
{
}

bool Sphere::Hit(const Ray & ray, float t_min, float t_max, HitRecord & hitRecord) const
{
	Vector3 oc = ray.Origin() - position;
	float a = Dot(ray.Direction(), ray.Direction());
	float b = Dot(oc, ray.Direction());
	float c = Dot(oc, oc) - radius * radius;
	float discriminant = b * b - a * c;
	if (discriminant > 0)
	{
		float temp = (-b - sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min)
		{
			hitRecord.t = temp;
			hitRecord.p = ray.PointAtParameter(temp);
			hitRecord.normal = (hitRecord.p - position) / radius;
			hitRecord.mat_ptr = this->material;
			return true;
		}
		temp = (-b + sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min)
		{
			hitRecord.t = temp;
			hitRecord.p = ray.PointAtParameter(temp);
			hitRecord.normal = (hitRecord.p - position) / radius;
			hitRecord.mat_ptr = this->material;
			return true;
		}
	}
	return false;
}
