#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ShaderProgram
{
	GLenum shaderType;
	int size = 0;
	int success;
	char infoLog[512];
	unsigned int shaderProgram;
	unsigned int shaderComponents[6];
	string tag;

public:
	ShaderProgram(string tag);
	void Init();
	bool AttachShaders();
	bool addShaderSource(const char* ShaderCode, GLenum shaderType);
	bool addShaderSourceFile(string fileName, GLenum shaderType);
	operator unsigned int() const;
};

