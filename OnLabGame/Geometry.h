#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

using namespace std;

class Geometry
{
public:
	void Init();
	virtual void Draw(unsigned int shaderProgram) = 0;
};

