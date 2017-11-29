#include "GameWindow.h"

void frame_buffer_size_callback(GLFWwindow* window, int width, int heigth) {
	glViewport(0, 0, width, heigth);
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
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

//	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
}

void GameWindow::close(){
	glfwTerminate();
}

int GameWindow::windowShouldClose()
{
	return glfwWindowShouldClose(window);
}

void GameWindow::onStartFrame(){	
	glfwPollEvents();
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GameWindow::onDrawFrame(){
	glfwSwapBuffers(window);

}

int GameWindow::Width()
{
	return width;
}

int GameWindow::Height()
{
	return height;
}

GameWindow::operator GLFWwindow*()
{
	return window;
}

