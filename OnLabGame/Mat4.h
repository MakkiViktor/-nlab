#pragma once
#include <math.h>
#include<iostream>
#include "Vec4.h"
#include <functional>

using namespace std;

class Mat4{
	float** m;
public:
	Mat4();
	Mat4(float m11, float m12, float m13, float m14,
		 float m21, float m22, float m23, float m24,
		 float m31, float m32, float m33, float m34,
		 float m41, float m42, float m43, float m44);
	Mat4(Mat4& const other);
	Mat4(Mat4&& other);
	void operator=(Mat4& const other);
	void operator=(Mat4&& other);
	Vec4& operator*(Vec4& const v);
	float& operator()(unsigned int r, unsigned int c);
	ostream& operator<<(ostream& os);
	Mat4& E();
	~Mat4();
};

Mat4& operator*(Mat4& const m, Mat4& const l);
Mat4& operator*(Vec4& const v, Mat4& const m);