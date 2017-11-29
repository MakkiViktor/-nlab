#pragma once
#include "GameBehaviour.h"
#include "GameWindow.h"
#include "IGameObject.h"
#include "ShaderProgram.h"
#include "Input.h"
#include "Mat4.h"
#include "Timer.h"

struct RenderState {
	Mat4 M;
	Mat4 Minv;
	Mat4 VP;
	Mat4 MVP;
	void init();
	void update();
};

class Game
{
public:
	static GameWindow* window;
	static RenderState renderState;
	Game(GameWindow* window);
	static void renderStateUpdate();
	void init();
	void start();
	void add(IGameObject* gob);
	void remove(IGameObject* gob);
};

