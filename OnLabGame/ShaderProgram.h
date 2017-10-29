#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include "GameBehaviour.h"

using namespace std;

class ShaderProgram : public GameBehaviour
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
	void init() override;
	void addShaderSource(const char* ShaderCode, GLenum shaderType);
	void addShaderSourceFile(string fileName, GLenum shaderType);
	void use();
	operator unsigned int() const;
};

