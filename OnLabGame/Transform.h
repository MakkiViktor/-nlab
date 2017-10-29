#pragma once
#include "Vec4.h"
#include "Mat4.h"

class Transform
{
	Vec4 position;
	//in radian TODO: ez legyen quaternio
	float roll, pitch, yaw;
public:
	void Translate(float x, float y, float z);
	void Translate(Vec4& v);
	void Rotate(float roll, float pitch, float yaw);
	void setRotation(float roll, float pitch, float yaw);
	Vec4& Position();
	Mat4& M();
};

