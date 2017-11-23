#pragma once
#include <vector>
#include "GameBehaviour.h"
#include <typeinfo.h>


using namespace std;

class IGameObject : public GameBehaviour{
protected:
	vector<IGameObject*> components;
public:	
	void addComponent(IGameObject* component);
	vector<IGameObject*>& getChildren();
	void onStartFrame() override;
	void onEndFrame() override;
	void init() override;
};
