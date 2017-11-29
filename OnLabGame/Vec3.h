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
	Vec3(const Vec3& other);
	Vec3(Vec3&& other);
	void operator=(const Vec3& other);
	void operator=(Vec3&& other);	
	//float& operator[](unsigned int index);
	Vec3 operator+(const Vec3& u);
	Vec3 operator-(const Vec3& u);
	Vec3 cross(const Vec3& u);
	Vec3 operator*(float s);
	float dot(const Vec3& u);
	float magnitude() const;
	Vec3 normalize();
	float cos(const Vec3& u);
	float& x();
	float& y();
	float& z();
	// Returns value in radian
	float alpha(const Vec3& u);
	operator float*();
	~Vec3();
};
	
	ostream& operator<<(ostream& os, Vec3& v);