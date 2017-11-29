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

	float normals[] = {
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,

		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f,
		0.0f, 0.0f, -1.0f
	};

	Vec3 position;
	Vec3 normal;
	for (int i = 0; i < 6; i++) {
		position = Vec3(vertices[i * 3], vertices[i * 3 + 1], vertices[i * 3 + 2]);
		normal = Vec3(normals[i * 3], normals[i * 3 + 1], normals[i * 3 + 2]);
		Geometry::addVertexData(position, normal);
	}

	Geometry::bufferData();

}

