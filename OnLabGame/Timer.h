#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Timer
{
public:
	static void start();
	static double timeEllapsed();
};

