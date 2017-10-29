#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderProgram.h"
#include "Geometry.h"
#include "TriangleGeometry.h"
#include "Material.h"
#include "Actor.h"
#include "Game.h"
#include "GameWindow.h"
#include "IGameObject.h"

int main() {
	Game game(GameWindow(800, 600, "Önlab Game"));
	game.init();
	//shaderek készítése
	ShaderProgram shaderProgram("simpleShaderProgram");
	//shaderProgram.init();
	shaderProgram.addShaderSourceFile("Simple_vs.glsl", GL_VERTEX_SHADER);
	shaderProgram.addShaderSourceFile("Simple_fs.glsl", GL_FRAGMENT_SHADER);
	//shaderProgram.attachShaders();

	TriangleGeometry triangle;
	//triangle.init();

	Material material(shaderProgram);
	Actor triangleMesh(material, triangle);
	game.start();
}


