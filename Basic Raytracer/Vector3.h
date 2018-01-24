#pragma once
#include <iostream>
#include <fstream>
#include <math.h>

class Vector3
{
public:
	float e[3];

	Vector3();
	Vector3(float e0, float e1, float e2);
	Vector3(const Vector3& v);
	~Vector3();

	// quick accesors
	float x() const;
	float y() const;
	float z() const;
	float r() const;
	float g() const;
	float b() const;

	// other functions
	void Normalize();
	Vector3 Normalized();
	float Magnitude();
	float SqrMagnitude();

	// operators
	const Vector3& operator+() const;
	Vector3 operator-() const;
	float operator[] (const int i) const;
	float& operator[] (const int i);

	Vector3& operator+=(const Vector3 &v);
	Vector3& operator-=(const Vector3 &v);
	Vector3& operator*=(const Vector3 &v);
	Vector3& operator/=(const Vector3 &v);
	Vector3& operator*=(const float s);
	Vector3& operator/=(const float s);

	//input
	friend std::istream& operator>>(std::istream& in, Vector3& v);
};

// binary operators
Vector3 operator+(const Vector3& v1, const Vector3& v2);
Vector3 operator-(const Vector3& v1, const Vector3& v2);
Vector3 operator*(const Vector3& v1, const Vector3& v2);
Vector3 operator/(const Vector3& v1, const Vector3& v2);
Vector3 operator+(const Vector3& v, const float s);
Vector3 operator*(const Vector3& v, const float s);
Vector3 operator/(const Vector3& v, const float s);
Vector3 operator*(float s, const Vector3& v);
Vector3 operator/(float s, const Vector3& v);

// output
std::ostream& operator<<(std::ostream &out, Vector3 v);

float Dot(const Vector3& v1, const Vector3& v2);
Vector3 Cross(const Vector3& v1, const Vector3& v2);
Vector3 Lerp(const Vector3& a, const Vector3& b, const float t);
