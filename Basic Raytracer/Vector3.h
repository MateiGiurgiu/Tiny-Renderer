#pragma once
#include <iostream>
#include <fstream>

class Vector3
{
public:
	float elements[3];

	Vector3();
	Vector3(float e0, float e1, float e2);
	Vector3(const Vector3& v);
	~Vector3();

	// quick accesors
	inline float x() const;
	inline float y() const;
	inline float z() const;
	inline float r() const;
	inline float g() const;
	inline float b() const;

	// operators
	inline const Vector3& operator+() const;
	inline Vector3 operator-() const;
	inline float operator[] (const int i) const;
	inline float& operator[] (const int i);

	inline Vector3& operator+=(const Vector3 &v);
	inline Vector3& operator-=(const Vector3 &v);
	inline Vector3& operator*=(const Vector3 &v);
	inline Vector3& operator/=(const Vector3 &v);
	inline Vector3& operator*=(const float s);
	inline Vector3& operator/=(const float s);

	friend std::ostream& operator<<(std::ostream &out, Vector3 v);
};

//inline Vector3 operator+(const Vector3& v1, const Vector3& v2);

