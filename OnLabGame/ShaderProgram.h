#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Mat4.h"
#include "Vec3.h"
#include "Quaternion.h"
#include "IGameObject.h"

using namespace std;

enum sharedType {
	MAT4, QUATERNION, VEC3, FLOAT
};


struct sharedUniform {
	sharedUniform(void* data, sharedType type, string& name) : data(data), type(type), name(name) {}
	void* data;
	sharedType type;
	string name;
};

class ShaderProgram : public IGameObject
{
	static vector<sharedUniform> shared;
	GLenum shaderType;
	int size = 0;
	int success;
	char infoLog[512];
	unsigned int shaderProgram;
	unsigned int shaderComponents[6];
	string tag;

public:
	ShaderProgram(string tag);
	~ShaderProgram();
	void init();
	void addShaderSource(const char* ShaderCode, GLenum shaderType);
	void addShaderSourceFile(string fileName, GLenum shaderType);
	static void addSharedUniform(sharedUniform& uniform);
	void setSharedUniform(string& name, void* data);
	void use();
	operator unsigned int() const;
};

