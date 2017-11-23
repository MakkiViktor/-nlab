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

//TODO game-nek statikus renderState, shader shareduniformban location ellen�rz�s(�gy csak azok a shaderek kapnak adatot, akik k�rnek) 
//meg kell neki delete v�ltoz� (ne pazaroljunk er�forr�st)
//Quaternion, Vec3, Mat4, Transform -ot �t kell n�zni, valahol sziv�rog

int main() {
	int WindowWidth(800);
	int WindowHeight(600);

	Game game(GameWindow(WindowWidth, WindowHeight, "�nlab Game"));
	game.init();

	//shaderek k�sz�t�se
	ShaderProgram shaderProgram("simpleShaderProgram");
	shaderProgram.addShaderSourceFile("Simple_vs.glsl", GL_VERTEX_SHADER);
	shaderProgram.addShaderSourceFile("Simple_fs.glsl", GL_FRAGMENT_SHADER);

	Transform tcam(Vec3(1, 0.5, 0));
	Camera3D camera(tcam, WindowWidth, WindowHeight, Vec3(1, 0.5, -1), Vec3(0, 1, 0));
	game.add(&camera);

	TriangleGeometry triangle;
	Material material(shaderProgram);
	Transform transform(Vec3(10,0, -10));
	Mesh triangleMesh(material, triangle);
	Actor triActor(transform);
	triActor.addComponent(&triangleMesh);
	game.add(&triActor);


	game.start();
}


