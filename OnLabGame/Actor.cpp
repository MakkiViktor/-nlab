#include "Actor.h"
#include "iostream"

Mat4 Actor::M;


Actor::Actor(Transform & trans):trans(trans)
{
	ShaderProgram::addSharedUniform(sharedUniform(M, MAT4, string("M")));

}

Transform& Actor::transform()
{
	return trans;
}

void Actor::onEndFrame()
{
	M = Mat4::Scale(trans.scale()) * trans.orientation().getMatrix() *  Mat4::Translate(trans.position());

	//cout << "S:" << S << endl;
	//cout << "T:" << T << endl;
	//cout << "R:" << R << endl;

	ShaderProgram::setSharedUniform(string("M"), M);

	IGameObject::onEndFrame();
}



