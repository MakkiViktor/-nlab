#include "Sun.h"

string Sun::TAG("Sun");

Sun::Sun()
{
	tag = Sun::TAG;
}

Sun::Sun(Vec3 position):Sun() {
	transform().position() = position;
}

Sun::~Sun()
{
	ShaderProgram::removeSharedUniform("sun");
}

void Sun::init()
{
	ShaderProgram::addSharedUniform(sharedUniform(transform().position(), VEC3, "sun"));

}

void Sun::onDrawUpdateFrame()
{
	ShaderProgram::setSharedUniform("sun", transform().position());
}
