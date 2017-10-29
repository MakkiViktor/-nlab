#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "string"
#include "stb_image.h"
#include <iostream>

using namespace std;

class Texture
{
private:
	unsigned int texture;
	unsigned char* imageData;
	int width, height, nrChannels;
	string ImageFileName;
public:
	Texture(string ImageFileName);
	void init();
	~Texture();
};

