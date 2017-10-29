#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Geometry.h"

using namespace std;

class TriangleGeometry : public Geometry {
public:
	TriangleGeometry();
	void init() override;
};

