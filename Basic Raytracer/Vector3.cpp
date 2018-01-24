#include "stdafx.h"
#include "Vector3.h"


Vector3::Vector3()
{
}

Vector3::Vector3(float e0, float e1, float e2)
{
	e[0] = e0;
	e[1] = e1;
	e[2] = e2;
}

Vector3::Vector3(const Vector3 & v)
{
	e[0] = v.x();
	e[1] = v.y();
	e[2] = v.z();
}

Vector3::~Vector3()
{
}

float Vector3::x() const { return e[0]; }
float Vector3::y() const { return e[1]; }
float Vector3::z() const { return e[2]; }
float Vector3::r() const { return e[0]; }
float Vector3::g() const { return e[1]; }
float Vector3::b() const { return e[2]; }

void Vector3::Normalize()
{
	this->operator/=(Magnitude());
}

Vector3 Vector3::Normalized()
{
	Vector3 v = *this;
	return v /= Magnitude();
}

float Vector3::Magnitude()
{
	return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}

float Vector3::SqrMagnitude()
{
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

const Vector3 & Vector3::operator+() const
{
	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-e[0], -e[1], -e[2]);
}

float Vector3::operator[](const int i) const
{
	return e[i];
}

float & Vector3::operator[](const int i)
{
	return e[i];
}

Vector3 & Vector3::operator+=(const Vector3 & v)
{
	e[0] += v[0];
	e[1] += v[1];
	e[2] += v[2];
	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 & v)
{
	e[0] -= v[0];
	e[1] -= v[1];
	e[2] -= v[2];
	return *this;
}

Vector3 & Vector3::operator*=(const Vector3 & v)
{
	e[0] *= v[0];
	e[1] *= v[1];
	e[2] *= v[2];
	return *this;
}

Vector3 & Vector3::operator/=(const Vector3 & v)
{
	e[0] /= v[0];
	e[1] /= v[1];
	e[2] /= v[2];
	return *this;
}

Vector3 & Vector3::operator*=(const float s)
{
	e[0] *= s;
	e[1] *= s;
	e[2] *= s;
	return *this;
}

Vector3 & Vector3::operator/=(const float s)
{
	e[0] /= s;
	e[1] /= s;
	e[2] /= s;
	return *this;
}

Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

Vector3 operator*(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

Vector3 operator/(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

Vector3 operator*(const Vector3& v, float s)
{
	return Vector3(v.x() * s, v.y() * s, v.z() * s);
}

Vector3 operator/(const Vector3& v, float s)
{
	return Vector3(v.x() / s, v.y() / s, v.z() / s);
}

Vector3 operator*(float s, const Vector3& v)
{
	return Vector3(s * v.x(), s * v.y(), s * v.z());
}

Vector3 operator/(float s, const Vector3& v)
{
	return Vector3(s / v.x(), s / v.y(), s / v.z());
}

// input/output
std::istream& operator>>(std::istream &in, Vector3 &v)
{
	in >> v.e[0] >> v.e[1] >> v.e[2];
	return in;
}

std::ostream & operator<<(std::ostream & out, Vector3 v)
{
	out << v.x() << " " << v.y() << " " << v.z();
	return out;
}

Vector3 Cross(const Vector3 & v1, const Vector3 & v2)
{
	return Vector3(
		v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1],
		-v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0],
		v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]
	);
}

float Dot(const Vector3 & v1, const Vector3 & v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

Vector3 Lerp(const Vector3 & a, const Vector3 & b, const float t)
{
	return a * (1 - t) + b * t;
}
