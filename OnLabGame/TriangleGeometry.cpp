#include "TriangleGeometry.h"

TriangleGeometry::TriangleGeometry() : Geometry(3){
}

void TriangleGeometry::init()
{
	Geometry::init();
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f };
	Geometry::addVertices(&vertices, sizeof(vertices), 3, 0);
}

