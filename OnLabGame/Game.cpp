#include "Game.h"

void Game::recursiveAdd(IGameObject * gob)
{
	for each(auto g in gob->getChildren())
	{
		recursiveAdd(g);
		gb->add(g);
	}
}

void Game::recursiveRemove(IGameObject * gob)
{
	for each (auto g in gob->getChildren())
	{
		recursiveRemove(g);
		gb->remove(g);
	}
}

Game::Game(GameWindow& window): window(&window){
	gb = new GameBehaviour();
}

Game::~Game()
{
	delete gb;
}

void Game::init(){
	window->init();
	glewExperimental = GL_TRUE;
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}
}

void Game::start(){

	gb->callInit();
	//Game loop
	while (!window->windowShouldClose()) {
		window->onStartFrame();
		gb->callOnStartFrame();
		gb->callOnEndFrame();
		window->onEndFrame();
	}
	window->close();
}

void Game::add(IGameObject * gob)
{
	recursiveAdd(gob);
	gb->add(gob);
}

void Game::remove(IGameObject * gob) {
	recursiveRemove(gob);
	gb->remove(gob);
}
