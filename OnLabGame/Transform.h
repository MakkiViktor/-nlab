#pragma once
#include "Vec3.h"
#include "Mat4.h"
#include "Quaternion.h"

class Transform
{
	Vec3 pos;
	Quaternion ori;
	Vec3 s;
	//in radian TODO: ez legyen quaternio
	//float roll, pitch, yaw;
public:
	Transform(Transform& other);
	Transform(Transform&& other);
	Transform(Vec3& dir);
	void Translate(float x, float y, float z);
	void Translate(Vec3& v);
	void Rotate(float roll, float pitch, float yaw);
	void Rotate(Quaternion q);

	Vec3& position();	
	Vec3& scale();
	Quaternion& orientation();
};

