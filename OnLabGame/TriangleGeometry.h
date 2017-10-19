#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Geometry.h"
using namespace std;

class TriangleGeometry : Geometry
{
	unsigned int vao, vbo;
public:
	TriangleGeometry();
	void Init();
	void Draw(unsigned int shaderProgram);
};

