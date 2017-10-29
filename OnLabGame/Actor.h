#pragma once
#include <vector>
#include "IDrawable.h"
#include "Material.h"
#include "Geometry.h"
#include "IGameObject.h"

using namespace std;

class Actor : public IDrawable, public IGameObject
{
	Material* material;
	Geometry* geometry;
	vector<Actor*> subActors;
public:
	Actor(Material& material, Geometry& geometry);
	void addSubActor(Actor& subActor);
	void addSubActors(vector<Actor*>& subActors);
	void onEndFrame() override;
	void draw() override;
};

