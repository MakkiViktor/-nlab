#pragma once
#include "Vec3.h"
#include "Mat4.h"
#include <math.h>

const int A = 0;
const int B = 1;
const int C = 2;
const int D = 3;

class Quaternion
{
	float* q;
public:
	Quaternion();
	Quaternion(float w, float x, float y, float z);
	Quaternion(float w, Vec3& const v);
	~Quaternion();
	Quaternion(Quaternion& const other);
	Quaternion(Quaternion&& other);

	void operator=(Quaternion& const other);
	void operator=(Quaternion&& other);
	Quaternion operator+(Quaternion& const v);
	Quaternion operator*(Quaternion& const v);
	Quaternion conjugate();
	static Quaternion& Euler(Vec3& axis, float angle);
	Mat4 getMatrix();
	Vec3 vector();
	const float* c_q();
};

