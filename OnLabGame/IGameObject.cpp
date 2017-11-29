#include "IGameObject.h"


string IGameObject::TAG("IGameObject");

void IGameObject::addComponent(IGameObject* component)
{
	component->parent = this;
	components.push_back(component);
}

vector<IGameObject*>& IGameObject::getComponents()
{
	return components;
}

IGameObject * IGameObject::getRoot()
{
	if(parent == nullptr)
		return this;
	return parent->getRoot();
}

IGameObject * IGameObject::getParent()
{
	return parent;
}

