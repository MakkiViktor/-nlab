#include "GameBehaviour.h"

class GameObjectContainer {
	static vector<GameBehaviour*> gobs;
public:
	static void add(GameBehaviour* gob) {
		gobs.push_back(gob);
	}

	static void remove(GameBehaviour* gob) {
		gobs.erase(std::remove(gobs.begin(), gobs.end(), gob), gobs.end());
	}

	static void doFunction(std::function<void(GameBehaviour*)> func) {
		for (std::vector<GameBehaviour*>::iterator it = gobs.begin(); it != gobs.end(); ++it)
		{
			func(*it);
		}
	}
};

std::vector<GameBehaviour*> GameObjectContainer::gobs;

GameBehaviour::GameBehaviour()
{
}

void GameBehaviour::add(GameBehaviour * gob)
{
	GameObjectContainer::add(gob);
}

void GameBehaviour::remove(GameBehaviour * gob) {
	GameObjectContainer::remove(gob);
}

void GameBehaviour::callInit(){
	GameObjectContainer::doFunction([](GameBehaviour* gob) {
		gob->init();
	});
}

void GameBehaviour::callOnStartFrame(){
	GameObjectContainer::doFunction([](GameBehaviour* gob) {
		gob->onStartFrame();
	});
}

void GameBehaviour::callOnEndFrame(){
	GameObjectContainer::doFunction([](GameBehaviour* gob) {
		gob->onEndFrame();
	});
}

void GameBehaviour::callDestroy()
{
	GameObjectContainer::doFunction([](GameBehaviour* gob) {
		gob->destroy();
	});
}

void GameBehaviour::callOnDrawFrame()
{
	GameObjectContainer::doFunction([](GameBehaviour* gob) {
		gob->onDrawFrame();
	});
}

void GameBehaviour::callOnDrawUpdateFrame()
{
	GameObjectContainer::doFunction([](GameBehaviour* gob) {
		gob->onDrawUpdateFrame();
	});
}
