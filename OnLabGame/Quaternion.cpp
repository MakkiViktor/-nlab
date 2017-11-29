#include "Quaternion.h"



Quaternion::Quaternion()
{
	q = new float[4];
	q[A] = 1.0f;
	q[B] = 0.0f;
	q[C] = 0.0f;
	q[D] = 0.0f;
}

Quaternion::Quaternion(float w, float x, float y, float z):Quaternion()
{
	q[A] = w; q[B] = x; q[C] = y; q[D] = z;
}

Quaternion::Quaternion(float w, Vec3 & const v):Quaternion(w, v[0], v[1], v[2]){}


Quaternion::~Quaternion()
{
	if (q != nullptr)
		delete[] q;
}

Quaternion::Quaternion(Quaternion & const other){
	q[A] = other.q[A];
	q[B] = other.q[B];
	q[C] = other.q[C];
	q[D] = other.q[D];
}

Quaternion::Quaternion(Quaternion && other)
{
	q = other.q;
	other.q = nullptr;
}

void Quaternion::operator=(Quaternion & const other)
{
	q[A] = other.q[A];
	q[B] = other.q[B];
	q[C] = other.q[C];
	q[D] = other.q[D];
}

void Quaternion::operator=(Quaternion && other)
{
	q = other.q;
	other.q = nullptr;
}

Quaternion Quaternion::operator+(Quaternion & const v)
{
	Quaternion result;
	result.q[B] = q[B] + v.q[B];
	result.q[C] = q[C] + v.q[C];
	result.q[D] = q[D] + v.q[D];
	result.q[A] = q[A] + v.q[A];
	return result;
}

Quaternion Quaternion::operator*(Quaternion & const v)
  {
	Quaternion result;
	result.q[A] = q[A] * v.q[A] - q[B] * v.q[B] - q[C] * v.q[C] - q[D] * v.q[D];
	result.q[B] = q[A] * v.q[B] + q[B] * v.q[A] + q[C] * v.q[D] - q[D] * v.q[C];
	result.q[C] = q[A] * v.q[C] - q[B] * v.q[D] + q[C] * v.q[A] + q[D] * v.q[B];
	result.q[D] = q[A] * v.q[D] + q[B] * v.q[C] - q[C] * v.q[B] + q[D] * v.q[A];
	return result;
}

Quaternion Quaternion::operator*(float s)
{
	Quaternion result;
	result.q[A] = q[A] * s;
	result.q[B] = q[B] * s;
	result.q[C] = q[C] * s;
	result.q[D] = q[D] * s;
	return result;
}

Quaternion Quaternion::conjugate()
{
	return Quaternion(q[A], -q[B], -q[C], -q[D]);
}

float Quaternion::magnitude()
{
	return sqrt(pow(q[A], 2.0f) + pow(q[B], 2.0f) + pow(q[C], 2.0f) + pow(q[D], 2.0f));
}

Quaternion Quaternion::normalize()
{
	float m = magnitude();
	return Quaternion(q[A]/m, q[B]/m, q[C]/m, q[D]/m);
}

Quaternion Quaternion::Euler(Vec3& axis, float angle)
{
	return Quaternion(cosf(angle / 2),axis * (-sinf(angle / 2)));
}

Mat4 Quaternion::getMatrix()
{
	return Mat4(q[A], -q[B], -q[C], -q[D],
				q[B],  q[A], -q[D],  q[C],
				q[C],  q[D],  q[A], -q[B],
				q[D], -q[C],  q[B],  q[A]);
}

Vec3 Quaternion::vector()
{
	return Vec3(q[B], q[C], q[D]).normalize();
}

const float * Quaternion::c_q()
{
	return q;
}




