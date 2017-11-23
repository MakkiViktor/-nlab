#pragma once
#include "Vec3.h"
#include "Actor.h"
#include <math.h>

class Camera3D : public Actor
{
	static Mat4 VP;
	float fov;
	float aspect;
	float fp = 1.0f;
	float bp = 1000.0f;
	Vec3 lookat;
	Vec3 up;
	Mat4 projM;
	Mat4 viewM;

	void calcProjectionMatrix();
	void calcViewMatrix();
public:
	Camera3D(Transform& trans,int windowWidth, int windowHeight, Vec3& lookat, Vec3& up);
	void onEndFrame() override;
	Vec3& Lookat();
	Vec3& Up();

};

