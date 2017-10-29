#include "ShaderProgram.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>


ShaderProgram::ShaderProgram(string tag):tag(tag){
}

void ShaderProgram::init()
{
	shaderProgram = glCreateProgram();
	for (int i = 0; i < size; i++) {
		glAttachShader(shaderProgram, shaderComponents[i]);
	}
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR:SHADER:LINKING FAILED " << tag << " : " << infoLog << std::endl;
	}
	for (int i = 0; i < size; i++) {
		glDeleteShader(shaderComponents[i]);
	}
}

void ShaderProgram::addShaderSource(const char * ShaderCode, GLenum shaderType)
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
	}
	size++;
}

void ShaderProgram::addShaderSourceFile(string fileName, GLenum shaderType)
{
	std::string line;
	std::string code;
	ifstream file(fileName);
	//TODO nem optimalis kell a kivételkezelés
	if (file.is_open()) {
		while (!file.eof()) {
			std::getline(file, line);
			code.append(line + "\n");
		}
		addShaderSource(code.c_str(), shaderType);
	}
	else {
		std::cout << "ERROR:SHADER:FILE OPEN FAILED\n" << tag;
	}
}

void ShaderProgram::use()
{
	glUseProgram(shaderProgram);
}

ShaderProgram::operator unsigned int() const
{
	return shaderProgram;
}


