#pragma once
#include "Camera3D.h"
#include "Input.h"
#include "Transform.h"
#include "Timer.h"

class CameraFlightController : public IGameObject
{
	const string Xaxis = "Xaxis";
	const string Yaxis = "Yaxis";
	const string Zaxis = "Zaxis";
	Transform * transform;
	Camera3D* camera;
	float sensivity;
public:
	float speed;
	int fps;
	CameraFlightController() :speed(5), fps(60), sensivity(10) {}
	void init() override;
	void onStartFrame() override;
};

