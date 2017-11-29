#include "Input.h"

vector<InputAxes*> Input::axes;
double Input::mousex = 0;
double Input::mousey = 0;
double Input::mouseDeltax = 0;
double Input::mouseDeltay = 0;

void Input::addCursorAxis(string name)
{
}

void Input::addAxes(Vec3& direction, string name, int positiveKey, int negativeKey)
{
	axes.push_back(new InputAxes(Vec3(0,0,0), direction, name, positiveKey, negativeKey));
}

void Input::refresh(GameWindow * window)
{
	int positiveState;
	int negativeState;
	double currentMousex;
	double currentMousey;
	int axisscalar = 0;

	glfwGetCursorPos(*window, &currentMousex, &currentMousey);
	if (&currentMousex != NULL && &currentMousey != NULL) {
		mouseDeltax = (currentMousex - mousex)/window->Width();
		mouseDeltay = (currentMousey - mousey)/window->Width();
		mousex = currentMousex;
		mousey = currentMousey;
	}

	for each (auto var in axes){
		positiveState = glfwGetKey(*window, var->positiveKey);
		negativeState = glfwGetKey(*window, var->negativeKey);
		if (positiveState == GLFW_PRESS) 
			axisscalar++;
		if (negativeState == GLFW_PRESS) 
			axisscalar--;
		var->axis = var->direction * axisscalar;
		axisscalar = 0;
	}
}

Vec3 Input::getAxis(string name)
{
	for each (auto var in axes){
		if (strcmp(var->name.c_str(), name.c_str()) == 0)
			return var->axis;
	}
}

double Input::getMouseDeltaX()
{
	return mouseDeltax;
}

double Input::getMouseDeltaY()
{
	return mouseDeltay;
}

void Input::deleteAxes()
{
	for each (auto var in axes){
		delete var;
	}
}
