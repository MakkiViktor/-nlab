#pragma once
#include "Vec3.h"
#include "Actor.h"
#include <math.h>

class Camera3D : public Actor
{
	static Mat4 V;
	static Mat4 P;
	float fov;
	float aspect;
	float fp = 0.0f;
	float bp = 1000.0f;
	Vec3 lookat;
	Vec3 up;
	Mat4 projM;
	Mat4 viewM;

	void calcProjectionMatrix();
	void calcViewMatrix();
public:
	Camera3D(Transform& trans, float fov, float aspect, Vec3& lookat, Vec3& up);
	void onEndFrame() override;

};

