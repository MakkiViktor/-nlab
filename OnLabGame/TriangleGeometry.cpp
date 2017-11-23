#include "TriangleGeometry.h"

TriangleGeometry::TriangleGeometry() : Geometry(6){
}

void TriangleGeometry::init()
{
	Geometry::init();
	float vertices[] = {
		-10.0f, -10.0f, 0.0f,
		10.0f,   10.0f, 0.0f,
		-10.0f,  10.0f, 0.0f,

		-10.0f, -10.0f, 0.0f,
		10.0f, -10.0f, 0.0f,
		10.0f,  10.0f, 0.0f,
		};
	Geometry::addVertices(&vertices, sizeof(vertices), 3, 0);
}

