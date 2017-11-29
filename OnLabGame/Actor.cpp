#include "Actor.h"
#include "iostream"

string Actor::TAG("Actor");

void Actor::renderStateUpdate()
{
	IGameObject* a = this;
	Actor* actor;
	Transform t(Vec3(0,0,0));
	while (a != nullptr) {
		//TODO scale-t be kell állítani
		if (strcmp(a->tag.c_str(), Actor::TAG.c_str()) == 0) {
			actor = static_cast<Actor*>(a);
			t.position() = t.position() + actor->transform().position();
			t.Rotate(actor->transform().orientation());
		}
		a = a->getParent();
	}
	Game::renderState.M = Mat4::Scale(t.scale()) * t.orientation().getMatrix() *  Mat4::Translate(t.position());
	Game::renderState.Minv = Mat4::Translate(t.position() * -1) * (t.orientation().conjugate()).getMatrix() * Mat4::Scale(Vec3(1 / t.scale()[0], 1 / t.scale()[1], 1 / t.scale()[2]));
	Game::renderStateUpdate();
}

Actor::Actor(Transform& trans):trans(trans)
{
	tag = Actor::TAG;
}

Actor::Actor()
{
}

Transform& Actor::transform()
{
	return trans;
}



