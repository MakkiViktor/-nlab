#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <functional>
#include "ShaderProgram.h"
#include "Geometry.h"
#include "TriangleGeometry.h"
#include "Material.h"
#include "Game.h"
#include "GameWindow.h"
#include "IGameObject.h"
#include "Transform.h"
#include "Actor.h"
#include "Mesh.h"
#include "Camera3D.h"


using namespace std;

int main() {
	int WindowWidth(800);
	int WindowHeight(600);

	Game game(GameWindow(WindowWidth, WindowHeight, "Önlab Game"));
	game.init();

	//shaderek készítése
	ShaderProgram shaderProgram("simpleShaderProgram");
	shaderProgram.addShaderSourceFile("Simple_vs.glsl", GL_VERTEX_SHADER);
	shaderProgram.addShaderSourceFile("Simple_fs.glsl", GL_FRAGMENT_SHADER);

	TriangleGeometry triangle;
	Material material(shaderProgram);
	Transform transform(Vec3(0,0,-1));
	Mesh triangleMesh(material, triangle);
	Actor triActor(transform);
	triActor.addComponent(triangleMesh);
	game.add(&triangleMesh);

	Transform tcam(Vec3(0, 0, 0));
	Camera3D camera(tcam, 3.14f, WindowWidth / WindowHeight, Vec3(0, 0, -1), Vec3(0, 1, 0));
	game.add(&camera);
	game.start();
}


