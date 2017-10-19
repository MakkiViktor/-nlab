#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

using namespace std;
/*
egy struktúra, amiben a vertexekhez fontos adatok vannak, még jól jöhet

struct vertex {
float* vertices = nullptr;
unsigned int location;
unsigned int dimension;

vertex(float* vertices, unsigned int dimension, unsigned int location) :
vertices(vertices), dimension(dimension), location(location) {}
};
*/


class Geometry
{
private:
	unsigned int vao, vbo;
	unsigned int vertexSize;
	//vector<vertex> vertices;
public:
	void init(unsigned int vertexSize);
	void addVertices(const GLvoid * vertices, size_t size, unsigned int dimension, unsigned int location);
	void draw();
};

