#include "IGameObject.h"

void IGameObject::addComponent(IGameObject* component)
{
	components.push_back(component);
}

vector<IGameObject*>& IGameObject::getChildren()
{
	return components;
}

void IGameObject::onStartFrame()
{
	for each (auto c in components)
	{
		c->onStartFrame();
	}
}

void IGameObject::onEndFrame()
{
	for each (auto c in components)
	{
		c->onEndFrame();
	}
}

void IGameObject::init()
{
	for each (auto c in components)
	{
		c->init();
	}
}


