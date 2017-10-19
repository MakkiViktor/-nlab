#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"

void Texture::init(string ImageFileName) {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	imageData = stbi_load(ImageFileName.c_str(), &width, &height, &nrChannels, 0);
	if (imageData) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
	}
	else {
		std::cout << "ERROR:TEXTURE:FAILED TO LOAD IMAGE" << std::endl;
	}
	stbi_image_free(imageData);
}


Texture::~Texture()
{
}
