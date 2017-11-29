#pragma once
#include <vector>
#include "Material.h"
#include "Geometry.h"
#include "IGameObject.h"
#include "Transform.h"
#include "Game.h"
#include <memory>

using namespace std;

class Actor : public IGameObject
{
	Transform trans;
protected:
	void renderStateUpdate();
public:
	static string TAG;
	Actor(Transform& trans);
	Actor();
	Transform& transform();
};

