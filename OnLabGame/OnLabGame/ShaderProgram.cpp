#include "ShaderProgram.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>


ShaderProgram::ShaderProgram(string tag):tag(tag){
}

void ShaderProgram::Init()
{
	shaderProgram = glCreateProgram();
}

bool ShaderProgram::AttachShaders()
{
	for (int i = 0; i < size; i++) {
		glAttachShader(shaderProgram, shaderComponents[i]);
	}
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR:SHADER:LINKING FAILED\n" << tag << "\n" << infoLog << std::endl;
		return false;
	}
	for (int i = 0; i < size; i++) {
		glDeleteShader(shaderComponents[i]);
	}
	return true;
}

bool ShaderProgram::addShaderSource(const char * ShaderCode, GLenum shaderType)
{
	shaderComponents[size] = glCreateShader(shaderType);
	glShaderSource(shaderComponents[size], 1, &ShaderCode, NULL);	
	glCompileShader(shaderComponents[size]);
	glGetShaderiv(shaderComponents[size], GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderComponents[size], 512, NULL, infoLog);
		std::cout << "ERROR:SHADER:COMPILATION FAILED\n" << tag << "\n" << infoLog << std::endl;
		glDeleteShader(shaderComponents[size]);
		return false;
	}
	size++;
	return true;
}

bool ShaderProgram::addShaderSourceFile(string fileName, GLenum shaderType)
{
	char* shaderCode;
	std::streampos length;
	ifstream file(fileName);
	//TODO nem optimalis kell a kivételkezelés
	if (file.is_open()) {
		file.seekg(0, std::ios::end);
		length = file.tellg();
		file.seekg(0, std::ios::beg);
		shaderCode = new char[(unsigned int) length];
		file.read(shaderCode, length);
		addShaderSource(shaderCode, shaderType);
		delete[] shaderCode;
		file.close();
	}
	else {
		std::cout << "ERROR:SHADER:FILE OPEN FAILED\n" << tag;
		return false;
	}

	return true;
}

ShaderProgram::operator unsigned int() const
{
	return shaderProgram;
}


