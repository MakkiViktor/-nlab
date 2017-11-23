#include "ShaderProgram.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>

std::vector<sharedUniform*> ShaderProgram::shared;



ShaderProgram::ShaderProgram(string tag):tag(tag){
}

ShaderProgram::~ShaderProgram()
{
	for each (auto s in shared)
	{
		delete s;
	}
	glDeleteShader(shaderProgram);
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
	cout << "ShaderProgram::shader succesfully linked " << tag << std::endl;
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
	cout << "ShaderProgram::shader succesfully added " << tag << std::endl;
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

void ShaderProgram::addSharedUniform(sharedUniform & uniform)
{
	for each (auto u in shared)
	{
		if (strcmp(u->name.c_str(), uniform.name.c_str()) == 0)
			return;
	}
	shared.push_back(new sharedUniform(uniform));
}

void ShaderProgram::setSharedUniform(string & name, float * data)
{
	for each (auto uniform in shared)
	{
		if (data == nullptr)
			throw exception("ERROR::ShaderProgram::No data to set");
		if (strcmp(uniform->name.c_str(), name.c_str()) == 0) {
			uniform->data = data;
			return;
		}
	}
	throw exception("ERROR::ShaderProgram::uniform does not exist");
}

void ShaderProgram::use()
{
	glUseProgram(shaderProgram);

	for each (auto uniform in shared)
	{
		switch (uniform->type) {
		case MAT4:
			glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniform->name.c_str()), 1, GL_FALSE, uniform->data);
			break;
		case VEC3: 
			glUniform3f(glGetUniformLocation(shaderProgram,uniform->name.c_str()), uniform->data[0], uniform->data[1], uniform->data[2]);
			break;
		case FLOAT: 
			glUniform1f(glGetUniformLocation(shaderProgram, uniform->name.c_str()), *uniform->data);
			break;

		}
	}

}

ShaderProgram::operator unsigned int() const
{
	return shaderProgram;
}


