#include "Game.h"

RenderState Game::renderState;
GameWindow* Game::window;
Game::Game(GameWindow* window){
	Game::window = window;
}

void Game::renderStateUpdate()
{
	renderState.update();
}

void Game::init(){	
	window->init();
	renderState.init();
	glewExperimental = GL_TRUE;
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}
}

void Game::start(){

	GameBehaviour::callInit();
	Timer::start();
	//Game loop
	while (!window->windowShouldClose()) {			
		window->onStartFrame();
		Input::refresh(window);
		GameBehaviour::callOnStartFrame();
		Timer::start();
		GameBehaviour::callOnDrawUpdateFrame();				
		GameBehaviour::callOnDrawFrame();
		window->onDrawFrame();
		GameBehaviour::callOnEndFrame();
	}
	Input::deleteAxes();
	window->close();
	GameBehaviour::callDestroy();
}

void Game::add(IGameObject * gob)
{	
	GameBehaviour::add(gob);
	for each (auto var in gob->getComponents())
	{
		add(var);
	}
}

void Game::remove(IGameObject * gob) {
	for each (auto var in gob->getComponents())
	{
		remove(var);
	}	
	GameBehaviour::remove(gob);
}

void RenderState::init()
{
	ShaderProgram::addSharedUniform(sharedUniform(MVP, MAT4, "MVP"));
	ShaderProgram::addSharedUniform(sharedUniform(M, MAT4, "M"));
	ShaderProgram::addSharedUniform(sharedUniform(Minv, MAT4, "Minv"));
}

void RenderState::update()
{
	MVP = M*VP;
	ShaderProgram::setSharedUniform("MVP", MVP);
	ShaderProgram::setSharedUniform("Minv", Minv);
	ShaderProgram::setSharedUniform("M", M);
}
