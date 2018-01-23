#include "stdafx.h"
#include "Vector3.h"


Vector3::Vector3()
{
}

Vector3::Vector3(float e0, float e1, float e2)
{
	elements[0] = e0;
	elements[1] = e1;
	elements[2] = e2;
}

Vector3::Vector3(const Vector3 & v)
{
	elements[0] = v.x();
	elements[1] = v.y();
	elements[2] = v.z();
}


Vector3::~Vector3()
{
}

inline float Vector3::x() const { return elements[0]; }
inline float Vector3::y() const { return elements[1]; }
inline float Vector3::z() const { return elements[2]; }
inline float Vector3::r() const { return elements[0]; }
inline float Vector3::g() const { return elements[1]; }
inline float Vector3::b() const { return elements[2]; }

inline const Vector3 & Vector3::operator+() const
{
	return *this;
}

inline Vector3 Vector3::operator-() const
{
	return Vector3(-elements[0], -elements[1], -elements[2]);
}

inline float Vector3::operator[](const int i) const
{
	return elements[i];
}

inline float & Vector3::operator[](const int i)
{
	return elements[i];
}

inline Vector3 Vector3::operator+=(const Vector3 & v)
{
	elements[0] += v[0];
	elements[1] += v[1];
	elements[2] += v[2];
	return *this;
}

inline Vector3 & Vector3::operator-=(const Vector3 & v)
{
	elements[0] -= v[0];
	elements[1] -= v[1];
	elements[2] -= v[2];
	return *this;
}

inline Vector3 & Vector3::operator*=(const Vector3 & v)
{
	elements[0] *= v[0];
	elements[1] *= v[1];
	elements[2] *= v[2];
	return *this;
}

inline Vector3 & Vector3::operator/=(const Vector3 & v)
{
	elements[0] /= v[0];
	elements[1] /= v[1];
	elements[2] /= v[2];
	return *this;
}

inline Vector3 & Vector3::operator*=(const float s)
{
	elements[0] *= s;
	elements[1] *= s;
	elements[2] *= s;
	return *this;
}

inline Vector3 & Vector3::operator/=(const float s)
{
	elements[0] /= s;
	elements[1] /= s;
	elements[2] /= s;
	return *this;
}



inline Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}

inline Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
}

inline Vector3 operator*(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() * v2.x(), v1.y() * v2.y(), v1.z() * v2.z());
}

inline Vector3 operator/(const Vector3& v1, const Vector3& v2)
{
	return Vector3(v1.x() / v2.x(), v1.y() / v2.y(), v1.z() / v2.z());
}

inline Vector3 operator*(const Vector3& v, float s)
{
	return Vector3(v.x() * s, v.y() * s, v.z() * s);
}

inline Vector3 operator/(const Vector3& v, float s)
{
	return Vector3(v.x() / s, v.y() / s, v.z() / s);
}

inline Vector3 operator*(float s, const Vector3& v)
{
	return Vector3(s * v.x(), s * v.y(), s * v.z());
}

inline Vector3 operator/(float s, const Vector3& v)
{
	return Vector3(s / v.x(), s / v.y(), s / v.z());
}

// input/output
inline std::istream& operator>>(std::istream &is, Vector3 &t)
{
	is >> t.elements[0] >> t.elements[1] >> t.elements[2];
	return is;
}

std::ostream & operator<<(std::ostream & out, Vector3 v)
{
	out << v.x() << " " << v.y() << " " << v.z();
	return out;
}
