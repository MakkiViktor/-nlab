#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "IDrawable.h"
#include "IGameObject.h"
#include "Vec3.h"

using namespace std;


//egy struktúra, amiben a vertexekhez fontos adatok vannak, még jól jöhet

struct VertexData {
	float position[3];
	float normal[3];
	//VertexData(const VertexData& other){
	//	position = other.position;
	//	normal = other.normal;
	//}
	//VertexData() {}
	//float texCoord[2];
};



class Geometry : public IDrawable, public IGameObject
{
private:
	unsigned int* vao,* vbo;
	unsigned int vertexSize;
	vector<VertexData> vertex;
public:
	Geometry(unsigned int vertexSize);
	Geometry(Geometry& other);
	Geometry(Geometry&& other);
	~Geometry();
	void addVertexData(Vec3& position, Vec3& normal);
	void bufferData();
	void init();
	void draw() override;
};

