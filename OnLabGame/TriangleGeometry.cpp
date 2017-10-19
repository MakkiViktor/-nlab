#include "TriangleGeometry.h"

TriangleGeometry::TriangleGeometry():Geometry() {
}


void TriangleGeometry::Init()
{
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f };

	std::cout << &vertices;
	Geometry::init(3);
	Geometry::addVertices(&vertices, sizeof(vertices), 3, 0);

}

void TriangleGeometry::Draw(unsigned int shaderProgram)
{
	glUseProgram(shaderProgram);
	Geometry::draw();
}

