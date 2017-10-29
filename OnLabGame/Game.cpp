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
	while (!window->windowShouldClose()) {
		window->onStartFrame();
		gb->callOnStartFrame();
		/*for each (IGameObject* gob in gobs)
		{
			gob->onStartFrame();
		}

		for each (IGameObject* gob in gobs)
		{
			gob->onEndFrame();
		}*/
		gb->callOnEndFrame();
		window->onEndFrame();
	}
	window->close();
}

