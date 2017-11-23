#pragma once
#include "GameBehaviour.h"
#include "IGameObject.h"
#include "GameWindow.h"

class Game
{
	GameWindow* window;
	GameBehaviour* gb;
public:
	Game(GameWindow& window);
	~Game();
	void init();
	void start();
	void add(IGameObject* gob);
	void remove(IGameObject* gob);
};

