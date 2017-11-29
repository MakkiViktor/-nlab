#include "Transform.h"

Transform::Transform(Transform & other)
{
	s = other.s;
	pos = other.pos;
	ori = other.ori;
}

Transform::Transform(Vec3& dir) :pos(dir)
{
	s = Vec3(1, 1, 1);
}

Transform::Transform()
{
	pos = Vec3(0, 0, 0);
	s = Vec3(1, 1, 1);
}

void Transform::Translate(float x, float y, float z) {
	pos[X] += x;
	pos[Y] += y;
	pos[Z] += z;
}

void Transform::Translate(Vec3& v) {
	pos = pos + v;
}

void Transform::Rotate(float roll, float pitch, float yaw) {
	Quaternion qr = Quaternion::Euler(Vec3(0, 0, 1), roll);
	Quaternion qp = Quaternion::Euler(Vec3(1, 0, 0), pitch);
	Quaternion qy = Quaternion::Euler(Vec3(0, 1, 0), yaw);

	ori = (qr * qp * qy * ori).normalize();
}

void Transform::Rotate(Quaternion& q)
{
	ori = q * ori;
}

void Transform::operator=(Transform & other)
{
	s = other.s;
	pos = other.pos;
	ori = other.ori;
}

Vec3& Transform::position() {
	return pos;
}

Vec3 & Transform::scale()
{
	return s;
}

Quaternion & Transform::orientation()
{
	return ori;
}

