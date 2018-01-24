#pragma once

#include "Vector3.h"
#include "Ray.h"

class Camera
{
public:
	Camera(const Vector3 bottomLeftCorner, const float horizontal, const float vertical);
	~Camera();

	Ray GetRay(const float u, const float v);

	Vector3 horizontal;
	Vector3 vertical;
	Vector3 origin;
	Vector3 bottomLeftCorner;
};

