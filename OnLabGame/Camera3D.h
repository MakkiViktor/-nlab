#pragma once
#include "Vec3.h"
#include "Actor.h"
#include "GameWindow.h"
#include <math.h>
#include "Game.h"
#include <iostream>

class Camera3D : public Actor
{
	unsigned int width;
	unsigned int height;
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
	void calcFovAspect();
public:
	static string TAG;
	Camera3D(Transform& trans,unsigned int width, unsigned int height, Vec3& lookat, Vec3& up);
	void onDrawUpdateFrame() override;
	void resize(unsigned int width, unsigned int height);
	Vec3& Lookat();
	Vec3& Up();
	void init() override;
};

