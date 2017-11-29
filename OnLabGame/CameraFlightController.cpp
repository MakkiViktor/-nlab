#include "CameraFlightController.h"


void CameraFlightController::init()
{
	//Chekkolni kell a getComponent mukodeset
	camera = getComponent<Camera3D>();
	transform = &camera->transform();
	Input::addAxes(Vec3(1, 0, 0), Xaxis, GLFW_KEY_D, GLFW_KEY_A);
	Input::addAxes(Vec3(0, 0, 1), Zaxis, GLFW_KEY_W, GLFW_KEY_S);
	Input::addAxes(Vec3(0, 1, 0), Yaxis, GLFW_KEY_E, GLFW_KEY_Q);
}

void CameraFlightController::onStartFrame()
{
	Vec3 move = Input::getAxis(Xaxis) + Input::getAxis(Yaxis) + Input::getAxis(Zaxis);
	double mousex = Input::getMouseDeltaX();
	double mousey = Input::getMouseDeltaY();
	double ellapsed = Timer::timeEllapsed();
	Vec3 v, foreward, right, up, dir;		
	
	foreward = (camera->Lookat() - transform->position()).normalize();
	up = camera->Up();
	right = foreward.cross(up);
	dir = ((foreward * move[Z]) + (right * move[X]) + (up * move[Y]));
	if (dir.magnitude() > 1)
		dir = dir.normalize();

	v = (Quaternion::Euler(Vec3(1, 0, 0), (sensivity)* mousey) * Quaternion::Euler(Vec3(0, 1, 0), (sensivity) * mousex) * Quaternion(0, foreward)).vector();
	camera->Lookat() = transform->position() + v.normalize();

	for (double t = 1.0/fps; t < ellapsed; t += 1.0/fps) {
		transform->position() = transform->position() + ( dir * (speed/fps)) ;
		camera->Lookat() = camera->Lookat() + (dir * (speed/fps));
	}

	
}
