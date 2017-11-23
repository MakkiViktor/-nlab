#pragma once
#include <vector>
#include "GameBehaviour.h"


using namespace std;

class IGameObject : public GameBehaviour{
protected:
	vector<IGameObject*> children;
	virtual void addComponent(IGameObject * child);
public:
	vector<IGameObject*>& getChildren();
};

