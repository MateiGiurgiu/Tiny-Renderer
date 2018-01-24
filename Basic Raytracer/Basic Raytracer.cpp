// Basic Raytracer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3.h"
#include "Ray.h"
#include <fstream>
using namespace std;

float SphereHit(const Vector3& center, const float radius, const Ray& ray)
{
	Vector3 oc = ray.Origin() - center;
	float a = Dot(ray.Direction(), ray.Direction());
	float b = 2.0 * Dot(oc, ray.Direction());
	float c = Dot(oc, oc) - radius * radius;
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		return -1;
	}
	else
	{
		return (-b - sqrt(discriminant)) / 2.0 * a;
	}
}

Vector3 Color(const Ray& r)
{
	float t = SphereHit(Vector3(0, 0, -1), 0.5, r);
	if(t > 0.0)
	{
		Vector3 N = r.PointAtParameter(t).Normalized() - Vector3(0, 0, -1);
		return 0.5 * Vector3(N.x() + 1, N.y() + 1, N.z() + 1);
	}
	Vector3 direction = r.Direction().Normalized();
	t = 0.5 * (direction.y() + 1.0);
	return Lerp(Vector3(1.0, 1.0, 1.0), Vector3(0.5, 0.7, 1.0), t);
}

int main()
{
	int nx = 500;
	int ny = 250;

	ofstream file("RenderOutput.ppm");
	if (file.is_open())
	{
		file << "P3\n" << nx << " " << ny << "\n255\n";
		Vector3 lower_left_corner(-2.0, -1.0, -1.0);
		Vector3 horizontal(4.0, 0.0, 0.0);
		Vector3 vertical(0.0, 2.0, 0.0);
		Vector3 origin(0.0, 0.0, 0.0);
		for (int y = ny - 1; y >= 0; y--)
		{
			for (int x = 0; x < nx; x++)
			{
				float u = float(x) / float(nx);
				float v = float(y) / float(ny);
				Ray ray(origin, lower_left_corner + u * horizontal + v * vertical);
				Vector3 col = Color(ray);
				int r = int(255.99 * col.r());
				int g = int(255.99 * col.g());
				int b = int(255.99 * col.b());

				file << r << " " << g << " " << b << endl;
			}
		}
	}

    return 0;
}

