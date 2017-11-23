#include "Geometry.h"

Geometry::Geometry(unsigned int vertexSize) : vertexSize(vertexSize){
	vao = new unsigned int;
	vbo = new unsigned int;
}

Geometry::Geometry(Geometry & other)
{
	vao = other.vao;
	vbo = other.vbo;
	vertexSize = other.vertexSize;
}

Geometry::Geometry(Geometry && other)
{
	vao = other.vao;
	vbo = other.vbo;
	vertexSize = other.vertexSize;
	other.vao = nullptr;
	other.vbo = nullptr;
}

Geometry::~Geometry()
{
	if (vao != nullptr) {
		glDeleteVertexArrays(1, vao);
		delete vao;
	}
	if (vbo != nullptr) {
		glDeleteBuffers(1, vbo);
		delete vbo;
	}

}

void Geometry::init(){
	glGenVertexArrays(1, vao);
	glGenBuffers(1, vbo);
}

void Geometry::addVertices(const GLvoid * vertices, size_t size, unsigned int dimension, unsigned int location){
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, dimension, GL_FLOAT, GL_FALSE, dimension * sizeof(float), 0);
	glEnableVertexAttribArray(location);
}

void Geometry::draw()
{
	glBindVertexArray(*vao);
	glDrawArrays(GL_TRIANGLES, 0, vertexSize);
}
