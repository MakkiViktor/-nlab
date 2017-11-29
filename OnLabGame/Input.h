#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vec3.h"
#include "GameWindow.h"
#include <string>
#include <vector>

using namespace std;

struct InputAxes {
	Vec3 axis;
	Vec3 direction;
	string name;
	int positiveKey;
	int negativeKey;
	InputAxes(Vec3 axis, Vec3 direction, string name, int positiveKey, int negativeKey)
		:axis(axis), direction(direction), name(name), positiveKey(positiveKey), negativeKey(negativeKey) {}
};

// A window dolga mehivni a pollevent() fv-t, az nélkül nem frissülnek a Key-ek
class Input
{
	static vector<InputAxes*> axes;
	static double mouseDeltax, mouseDeltay;
	static double mousex, mousey;
public:
	static void addCursorAxis(string name);
	static void addAxes(Vec3& direction, string name, int positiveKey, int negativeKey);
	static void refresh(GameWindow* window);
	static Vec3 getAxis(string name);
	static double getMouseDeltaX();
	static double getMouseDeltaY
	();
	static void deleteAxes();
};

