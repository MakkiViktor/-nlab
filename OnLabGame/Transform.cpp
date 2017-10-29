#include "Transform.h"

void Transform::Translate(float x, float y, float z) {
	position[X] = x;
	position[Y] = y;
	position[Z] = z;
}

void Transform::Translate(Vec4& v) {
	position = position + v;
}

void Transform::Rotate(float roll, float pitch, float yaw) {
	
}

void Transform::setRotation(float roll, float pitch, float yaw) {

}
Vec4& Transform::Position() {

}
Mat4& M();

