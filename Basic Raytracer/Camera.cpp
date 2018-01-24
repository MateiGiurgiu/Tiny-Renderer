#include "stdafx.h"
#include "Camera.h"

Camera::Camera(const Vector3 bottomLeftCorner, const float horizontal, const float vertical)
{
	this->origin = Vector3(0.0f, 0.0f, 0.0f);
	this->bottomLeftCorner = bottomLeftCorner;
	this->horizontal = Vector3(horizontal, 0.0f, 0.0f);
	this->vertical = Vector3(0.0f, vertical, 0.0f);
}

Camera::~Camera()
{
}

Ray Camera::GetRay(const float u, const float v)
{
	return Ray(origin, bottomLeftCorner + u * horizontal + v * vertical - origin);
}
