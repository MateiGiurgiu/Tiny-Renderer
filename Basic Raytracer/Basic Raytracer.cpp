// Basic Raytracer.cpp : Defines the entry point for the console application.
// Matei Giurgiu - 2018

#include "stdafx.h"
#include "SurfaceList.h"
#include "Sphere.h"
#include <fstream>
#include "float.h"
#include "camera.h"
#include <iostream>
#include <random>
#include <Windows.h>
#include "Material.h";
#include "Lambertian.h"
#include "Metal.h"
using namespace std;

// random related
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dist(0, 1);

Vector3 RandomInUnitSphere()
{
	Vector3 p;
	do
	{
		p = 2.0f * Vector3(dist(gen), dist(gen), dist(gen)) - Vector3(1, 1, 1);
	} while (p.Magnitude() >= 1.0f);
	
	return p;
}


Vector3 Color(const Ray& ray, SurfaceList *scene, int depth) 
{
	HitRecord hitRecord;
	if (scene->Hit(ray, 0.001, FLT_MAX, hitRecord))
	{
		Ray scattered;
		Vector3 attenuation;
		if (depth < 50 && hitRecord.mat_ptr->scatter(ray, hitRecord, attenuation, scattered))
		{
			return attenuation * Color(scattered, scene, depth + 1);
		}
		else return Vector3(0, 0, 0);
	}
	else
	{
		Vector3 direction = Normalize(ray.Direction());
		float t = 0.5f * (direction.y() + 1.0f);
		return Lerp(Vector3(1.0f, 1.0f, 1.0f), Vector3(0.5f, 0.7f, 1.0f), t);
	}
}

int main()
{
	int nx = 400;
	int ny = 300;
	int ns = 100;

	ofstream file("RenderOutput.ppm");
	if (file.is_open())
	{
		// create the scene
		Surface* sceneObjects[4];
		sceneObjects[0] = new Sphere(Vector3(0.0f, 0.0f, -1.0f), 0.5f, new Lambertian(Vector3(0.8, 0.3, 0.3)));
		sceneObjects[1] = new Sphere(Vector3(0.0f, -100.5f, -1.0f), 100, new Lambertian(Vector3(0.8, 0.3, 0.0)));
		sceneObjects[2] = new Sphere(Vector3(1.0f, 0.0, -1.0f), 0.5, new Metal(Vector3(0.8,0.6,0.2), 0.9));
		sceneObjects[3] = new Sphere(Vector3(-1.0f, 0.0f, -1.0f), 0.5, new Metal(Vector3(0.8,0.8,0.8), 0.25));

		SurfaceList* scene = new SurfaceList(sceneObjects, 4);
		
		// create camera
		Camera camera(Vector3(-2.0f, -1.5f, -1.0f), 4.0f, 3.0f);

		cout << "Rendering started..." << endl;

		LARGE_INTEGER start, end, frequency;
		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&start);

		file << "P3\n" << nx << " " << ny << "\n255\n";
		for (int y = ny - 1; y >= 0; y--)
		{
			for (int x = 0; x < nx; x++)
			{
				Vector3 col(0.0f, 0.0f, 0.0f);
				for (int s = 0; s < ns; s++)
				{
					float u = float(x + dist(gen)) / float(nx);
					float v = float(y + dist(gen)) / float(ny);
					Ray ray = camera.GetRay(u, v);
					col += Color(ray, scene, 0);
				}
				col /= float(ns);
				// gamma correction
				col = Vector3(sqrt(col.r()), sqrt(col.g()), sqrt(col.b()));
				int r = int(255.99 * col.r());
				int g = int(255.99 * col.g());
				int b = int(255.99 * col.b());

				file << r << " " << g << " " << b << endl;
			}
		}
		file.close();
		QueryPerformanceCounter(&end);
		float time = (end.QuadPart - start.QuadPart) / (static_cast<float> (frequency.QuadPart));
		int minutes = static_cast<int>(time / 60);
		int seconds = time - minutes * 60.0f;
		cout << "Render finished!!! Total Time: (" << time << "sec) " << minutes << ":" << seconds << endl;
		cout << "Press any key to close" << endl;
		cin.get();
	}

    return 0;
}

