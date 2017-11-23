#include "Camera3D.h"
#include <iostream>

Mat4 Camera3D::P;
Mat4 Camera3D::V;

Camera3D::Camera3D(Transform& trans, float fov, float aspect, Vec3& lookat, Vec3& up) : 
	Actor(trans), fov(fov), aspect(aspect), lookat(lookat), up(up)
{
	ShaderProgram::addSharedUniform(sharedUniform(&V, MAT4, string("V")));
	ShaderProgram::addSharedUniform(sharedUniform(&P, MAT4, string("P")));
}

void Camera3D::onEndFrame()
{
	calcProjectionMatrix();
	calcViewMatrix();
	V = viewM;
	P = projM;

	std::cout << "V:" << std::endl << V << std::endl;
	std::cout << "P:" << std::endl << P << std::endl;
}

void Camera3D::calcProjectionMatrix()
{
	projM(0, 0) = 1.0f / (tanf(fov / 2.0f) * aspect);
	projM(1, 1) = 1.0f / tanf(fov / 2.0f);
	projM(2, 2) = -(fp + bp) / (bp - fp);
	projM(2, 3) = -1.0;
	projM(3, 2) = -2 * fp * bp / (bp - fp);
}

void Camera3D::calcViewMatrix()
{
	Vec3 scale = transform().scale();
	scale[X] = 1 / scale[X];
	scale[Y] = 1 / scale[Y];
	scale[Z] = 1 / scale[Z];

	Vec3 p = transform().position();
	Vec3 f = lookat - transform().position();
	Vec3 r = f.cross(up).normalize();
	Vec3 u = r.cross(f);

	Mat4 TR(
		r[X], u[X], f[X], p[X],
		r[Y], u[Y], f[Y], p[Y],
		r[Z], u[Z], f[Z], p[Z],
		0.0f, 0.0f, 0.0f, 1.0f
	);

	Mat4 S = Mat4::Scale(scale);
	viewM = TR * S;
}
