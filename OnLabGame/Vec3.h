#pragma once
#include "stdexcept"
#include <math.h>
#include <iostream>

using namespace std;

const int X = 0;
const int Y = 1;
const int Z = 2;

class Vec3
{
	float* v;
public:
	Vec3();
	Vec3(float x, float y, float z);
	Vec3(Vec3& const other);
	Vec3(Vec3&& other);
	void operator=(Vec3& const other);
	void operator=(Vec3&& other);	
	float& operator[](unsigned int index);
	Vec3 operator+(Vec3& const u);
	Vec3 operator-(Vec3& const u);
	Vec3 cross(Vec3& const u);
	Vec3 operator*(float s);
	float dot(Vec3& const u);
	float magnitude();
	Vec3 normalize();
	float cos(Vec3& const u);
	float& x();
	float& y();
	float& z();
	// Returns value in radian
	float alpha(Vec3& const u);
	ostream& operator<<(ostream& os);
	~Vec3();
};

