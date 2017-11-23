#include "Actor.h"
#include "iostream"

Mat4 Actor::S;
Mat4 Actor::R;
Mat4 Actor::T;

Actor::Actor(Transform & trans):trans(trans)
{
	ShaderProgram::addSharedUniform(sharedUniform(&S, MAT4, string("S")));
	ShaderProgram::addSharedUniform(sharedUniform(&R, MAT4, string("R")));
	ShaderProgram::addSharedUniform(sharedUniform(&T, MAT4, string("T")));
}

void Actor::addComponent(IGameObject & component){
	IGameObject::addComponent(&component);
	components.push_back(&component);
}

// hozzáfúz a vectorhoz
void Actor::addComponents(vector<IGameObject*>& components){
	this->components.insert(std::end(this->components), std::begin(components), std::end(components));
	for each (auto a in components)
	{
		IGameObject::addComponent(a);
	}
}

Transform& Actor::transform()
{
	return trans;
}

void Actor::onEndFrame()
{
	S = Mat4::Scale(trans.scale());
	T = Mat4::Translate(trans.position());
	R = trans.orientation().getMatrix();

	std::cout << "S:" << std::endl << S << std::endl;
	std::cout << "T:" << std::endl << T << std::endl;
	std::cout << "R:" << std::endl << R << std::endl;
}



