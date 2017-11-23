#include "TriangleGeometry.h"

TriangleGeometry::TriangleGeometry() : Geometry(6){
}

void TriangleGeometry::init()
{
	Geometry::init();
	float vertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f,   1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,

		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		1.0f,  1.0f, 0.0f,
		};
	Geometry::addVertices(&vertices, sizeof(vertices), 3, 0);
}

