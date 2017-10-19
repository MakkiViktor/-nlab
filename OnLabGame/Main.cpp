#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderProgram.h"
#include "Geometry.h"
#include "TriangleGeometry.h"

//Átméretezés callback
void frame_buffer_size_callback(GLFWwindow* window, int width, int heigth) {
	glViewport(0,0,width, heigth);
}

// Bemenetek kezelése
void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OnLabGame", NULL, NULL);
	if (window == NULL) {
		std::cout << "Nem sikerult ablakot letrehozni" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glViewport(0, 0, 800, 600);
	// Átméretezés callback megadása
	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);


	glewExperimental = GL_TRUE;
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}

	//shaderek készítése
	ShaderProgram shaderProgram("simpleShaderProgram");
	shaderProgram.init();
	shaderProgram.addShaderSourceFile("Simple_vs.glsl", GL_VERTEX_SHADER);
	shaderProgram.addShaderSourceFile("Simple_fs.glsl", GL_FRAGMENT_SHADER);
	shaderProgram.attachShaders();

	TriangleGeometry triangle;
	triangle.Init();

	//Game loop
	while (!glfwWindowShouldClose(window)) {
		//input
		processInput(window);
		//rendering
		triangle.Draw(shaderProgram);

		//events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}


