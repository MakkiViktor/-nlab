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

void Geometry::addVertexData(Vec3& position, Vec3& normal){
	VertexData data;
	for (int i = 0; i < 3; i++) {
		data.position[i] = position[i];
		data.normal[i] = normal[i];
	}
	vertex.push_back(data);
}

void Geometry::bufferData()
{	
	vertexSize = vertex.size();
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);	
	// Új Bufferdata-nál nem újat hoz létre, hanem ezt írja felül
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(VertexData), &vertex[0], GL_STATIC_DRAW);	



	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	//glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, position));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexData), (void*)offsetof(VertexData, normal));
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)offsetof(VertexData, texCoord));
}

void Geometry::draw()
{
	glBindVertexArray(*vao);
	glDrawArrays(GL_TRIANGLES, 0, vertexSize);
}


