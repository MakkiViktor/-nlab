#pragma once
#include "stdexcept"
#include <math.h>
#include <iostream>

using namespace std;

const int X = 0;
const int Y = 1;
const int Z = 2;

class Vec4
{
	float* v;
public:
	Vec4();
	Vec4(float x, float y, float z);
	Vec4(Vec4& const other);
	Vec4(Vec4&& other);
	void operator=(Vec4& const other);
	void operator=(Vec4&& other);	
	float& operator[](unsigned int index);
	Vec4& operator+(Vec4& const u);
	Vec4& operator-(Vec4& const u);
	Vec4& operator*(Vec4& const u);
	Vec4& operator*(float s);
	float dot(Vec4& const u);
	float abs();
	float cos(Vec4& const u);
	// Returns value in radian
	float alpha(Vec4& const u);
	ostream& operator<<(ostream& os);
	~Vec4();
};

