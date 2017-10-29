#include "GameBehaviour.h"

class GameObjectContainer {
	static vector<GameBehaviour*> gobs;
public:
	static void add(GameBehaviour* gob) {
		gobs.push_back(gob);
	}

	static void doFunction(std::function<void(GameBehaviour*)> func) {
		for each (auto gob in gobs)
		{
			func(gob);
		}
	}
};

std::vector<GameBehaviour*> GameObjectContainer::gobs;

GameBehaviour::GameBehaviour()
{
	GameBehaviour::add(this);
}

void GameBehaviour::add(GameBehaviour * gob)
{
	GameObjectContainer::add(gob);
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
