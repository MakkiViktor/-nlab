#include "Camera3D.h"

string Camera3D::TAG("Camera3D");

Camera3D::Camera3D(Transform& trans,unsigned int width, unsigned int height, Vec3& lookat, Vec3& up) : 
	Actor(trans),width(width), height(height), lookat(lookat), up(up)
{
	tag = Camera3D::TAG;
	calcFovAspect();
	calcProjectionMatrix();
	transform().orientation() = Quaternion(0, lookat.normalize());
}

void Camera3D::onDrawUpdateFrame()
{
	calcViewMatrix();
	Game::renderState.VP = viewM * projM;
	ShaderProgram::setSharedUniform("cam", transform().position());
}

void Camera3D::resize(unsigned int width, unsigned int height)
{
	this->width = width;
	this->height = height;
	calcFovAspect();
	calcProjectionMatrix();
}

Vec3 & Camera3D::Lookat()
{
	return lookat;
}

Vec3 & Camera3D::Up()
{
	return up;
}

void Camera3D::init()
{
	ShaderProgram::addSharedUniform(sharedUniform(transform().position(), VEC3, "cam"));
}

void Camera3D::calcProjectionMatrix()
{
	projM(0, 0) = (1.0f / (tanf(fov / 2.0f)*aspect));
	projM(1, 1) = 1.0f / tanf(fov / 2.0f);
	projM(2, 2) = -(fp + bp) / (bp - fp);
	projM(2, 3) = -1.0f;
	projM(3, 2) = -2.0f * fp * bp / (bp - fp);
}

void Camera3D::calcViewMatrix()
{
	Vec3 scale = transform().scale();
	scale[X] = 1 / scale[X];
	scale[Y] = 1 / scale[Y];
	scale[Z] = 1 / scale[Z];

	Vec3 p = transform().position();
	Vec3 f = (transform().position() - lookat).normalize();
	Vec3 r = up.cross(f).normalize();
	Vec3 u = f.cross(r);

	Mat4 TR(
		r[X], u[X], f[X], 0.0f,
		r[Y], u[Y], f[Y], 0.0f,
		r[Z], u[Z], f[Z], 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);

	//Mat4 TR = transform().orientation().getMatrix().transpose();
	Vec3 eye = transform().position()*-1;
	viewM = Mat4::Translate(eye) * TR;
}

void Camera3D::calcFovAspect()
{
	aspect = width / height;
	fov = atanf(width / aspect);
}
