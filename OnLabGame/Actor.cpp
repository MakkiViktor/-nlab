#include "Actor.h"

Actor::Actor(Material& material, Geometry& geometry) : material(&material), geometry(&geometry) {}

void Actor::addSubActor(Actor & subActor){
	subActors.push_back(&subActor);
}

// hozzáfúz a vectorhoz
void Actor::addSubActors(vector<Actor*>& subActors){
	this->subActors.insert(std::end(this->subActors), std::begin(subActors), std::end(subActors));
}

void Actor::onEndFrame(){
	draw();
}

void Actor::draw()
{
	for each (Actor* var in subActors){
		var->draw();
	}
	material->draw();
	geometry->draw();
}


