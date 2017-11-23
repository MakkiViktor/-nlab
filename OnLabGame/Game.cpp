#include "Game.h"

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
	gb->add(gob);
}

void Game::remove(IGameObject * gob) {
	gb->remove(gob);
}
