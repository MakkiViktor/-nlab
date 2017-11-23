#include "Camera3D.h"
#include <iostream>

Mat4 Camera3D::VP;

Camera3D::Camera3D(Transform& trans, int windowWidth, int windowHeight, Vec3& lookat, Vec3& up) : 
	Actor(trans), lookat(lookat), up(up)
{
	aspect = windowWidth / windowHeight;
	fov = atanf(windowWidth / aspect);
	ShaderProgram::addSharedUniform(sharedUniform(VP, MAT4, string("VP")));
	calcProjectionMatrix();
	transform().orientation() = Quaternion(0, lookat.normalize());
}

void Camera3D::onEndFrame()
{

	calcViewMatrix();
	VP = projM * viewM;
	//cout << "V:" << V << endl;
	//cout << "P:" << P << endl;

	ShaderProgram::setSharedUniform(string("VP"), VP);
}

Vec3 & Camera3D::Lookat()
{
	return lookat;
}

Vec3 & Camera3D::Up()
{
	return up;
}

void Camera3D::calcProjectionMatrix()
{
	projM(0, 0) = (1.0f / tanf(fov / 2.0f)) / aspect;
	projM(1, 1) = 1.0f / tanf(fov / 2.0f);
	projM(2, 2) = -(fp + bp) / (bp - fp);
	projM(3, 2) = -1.0f;
	projM(2, 3) = -2.0f * fp * bp / (bp - fp);
}

void Camera3D::calcViewMatrix()
{
	Vec3 scale = transform().scale();
	scale[X] = 1 / scale[X];
	scale[Y] = 1 / scale[Y];
	scale[Z] = 1 / scale[Z];

	Vec3 p = transform().position();
	Vec3 f = (transform().position() - lookat).normalize() * -1;
	Vec3 r = up.cross(f).normalize() * -1;
	Vec3 u = f.cross(r) * -1;

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
