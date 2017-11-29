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
#include "Sun.h"
#include "CameraFlightController.h"


using namespace std;

//TODO game-nek statikus renderState, shader shareduniformban location ellenõrzés(így csak azok a shaderek kapnak adatot, akik kérnek) 
//meg kell neki delete változó (ne pazaroljunk erõforrást)
//Quaternion, Vec3, Mat4, Transform -ot át kell nézni, valahol szivárog

int main() {

	int WindowWidth(800);
	int WindowHeight(800);

	GameWindow window(WindowWidth, WindowHeight, "Önlab Game");

	Game game(&window);
	game.init();

	//shaderek készítése
	ShaderProgram shaderProgram("simpleShaderProgram");
	shaderProgram.addShaderSourceFile("Simple_vs.glsl", GL_VERTEX_SHADER);
	shaderProgram.addShaderSourceFile("Simple_fs.glsl", GL_FRAGMENT_SHADER);

	CameraFlightController c;

	Transform tcam(Vec3(1, 0, 0));
	Camera3D camera(tcam, WindowWidth, WindowHeight, Vec3(1, 0, -1), Vec3(0, 1, 0));
	camera.addComponent(&c);
	game.add(&camera);

	TriangleGeometry triangle;
	Material material(shaderProgram, Vec3(0,0,1));
	Transform transform(Vec3(10,0, -20));
	Mesh triangleMesh(material, triangle);
	Actor triActor(transform);
	triActor.transform().Rotate(0.0f, 1.0f, 0.0f);
	triActor.addComponent(&triangleMesh);
	game.add(&triActor);

	Sun sun(Vec3(-5,0,-10));

	game.add(&sun);

	game.start();

}


