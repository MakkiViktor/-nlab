#include "IGameObject.h"

void IGameObject::addComponent(IGameObject * child)
{	
	children.push_back(child);
}

vector<IGameObject*>& IGameObject::getChildren()
{
	return children;
}

