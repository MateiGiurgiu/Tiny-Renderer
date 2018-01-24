#include "stdafx.h"
#include "Ray.h"


Ray::Ray()
{
}

Ray::Ray(const Vector3 & a, const Vector3 & b)
{
	this->A = a;
	this->B = b;
}

Ray::Ray(const Ray & r)
{
	this->A = r.A;
	this->B = r.B;
}


Ray::~Ray()
{
}

Vector3 Ray::Origin() const
{
	return A;
}

Vector3 Ray::Direction() const
{
	return B;
}

Vector3 Ray::PointAtParameter(const float t) const
{
	return A + t * B;
}
