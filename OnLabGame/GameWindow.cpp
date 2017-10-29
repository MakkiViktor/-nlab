#include "GameWindow.h"

void frame_buffer_size_callback(GLFWwindow* window, int width, int heigth) {
	glViewport(0, 0, width, heigth);
}

// Bemenetek kezelése
void processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}


GameWindow::GameWindow(unsigned int width, unsigned int height, string windowName)
	: width(width), height(height), windowName(windowName){}

GameWindow::~GameWindow()
{
	close();
}

void GameWindow::init()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
	if (window == NULL) {
		std::cout << "ERROR:WINDOW:FAILED TO CREATE WINDOW" << std::endl;
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);
	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
}

void GameWindow::close(){
	glfwTerminate();
}

int GameWindow::windowShouldClose()
{
	return glfwWindowShouldClose(window);
}

void GameWindow::onStartFrame(){
	processInput(window);
}

void GameWindow::onEndFrame(){
	glfwSwapBuffers(window);
	glfwPollEvents();
}
