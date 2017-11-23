#include "Geometry.h"

Geometry::Geometry(unsigned int vertexSize) : vertexSize(vertexSize){}

void Geometry::init(){
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
}

void Geometry::addVertices(const GLvoid * vertices, size_t size, unsigned int dimension, unsigned int location){
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, dimension, GL_FLOAT, GL_FALSE, dimension * sizeof(float), 0);
	glEnableVertexAttribArray(location);
}

void Geometry::draw()
{
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, vertexSize);
}
