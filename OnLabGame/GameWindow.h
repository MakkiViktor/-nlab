#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

using namespace std;

class GameWindow {
	GLFWwindow* window;
	unsigned int width;
	unsigned int height;
	string windowName;
public:
	GameWindow(unsigned int width, unsigned int height, string windowName);
	~GameWindow();
	void init();
	void close();
	int windowShouldClose();
	void onStartFrame();
	void onEndFrame();
};

