#include "Vec4.h"

Vec4::Vec4()
{
	v = new float[4];
	v[3] = 1.0f;
}

Vec4::Vec4(float x, float y, float z):Vec4() {
	v[X] = x; v[Y] = y; v[Z] = z;
}

Vec4::Vec4(Vec4& const other): Vec4() {
	v[X] = other[X];
	v[Y] = other[Y];
	v[Z] = other[Z];
}
Vec4::Vec4(Vec4&& other) {
	v = other.v;
	other.v = nullptr;
}
void Vec4::operator=(Vec4& const other) {
	v[X] = other[X];
	v[Y] = other[Y];
	v[Z] = other[Z];
}

void Vec4::operator=(Vec4&& other) {
	v = other.v;
	other.v = nullptr;
}

float& Vec4::operator[](unsigned int index){
	return v[index];
}

Vec4& Vec4::operator+(Vec4& const u) {
	Vec4 result;
	result[X] = v[X] + u[X];
	result[Y] = v[Y] + u[Y];
	result[Z] = v[Z] + u[Z];
	return result;
}
Vec4& Vec4::operator-(Vec4& const u) {
	Vec4 result;
	result[X] = v[X] - u[X];
	result[Y] = v[Y] - u[Y];
	result[Z] = v[Z] - u[Z];
	return result;
}
Vec4& Vec4::operator*(Vec4& const u) {
	Vec4 result;
	result[X] = v[Y] * u[Z] - v[Z] * u[Y];
	result[Y] = v[Z] * u[X] - v[X] * u[Z];
	result[Z] = v[X] * u[Y] - v[Y] * u[X];
	return result;
}

Vec4& Vec4::operator*(float s) {
	Vec4 result;
	result[X] = v[X] * s;
	result[Y] = v[Y] * s;
	result[Z] = v[Z] * s;
	return result;
}
float Vec4::dot(Vec4& const u) {
	float result = v[X] * u[X] + v[Y] * u[Y] + v[Z] * u[Z];
}

float Vec4::abs() {
	float result = sqrt(pow(v[X], 2) + pow(v[Y], 2) + pow(v[Z], 2));
	return result;
}

float Vec4::cos(Vec4& const u) {
	float cos = dot(u) / abs() * u.abs();
	return cos;
}

float Vec4::alpha(Vec4& const u) {
	return acosf(cos(u));
}

ostream & Vec4::operator<<(ostream & os){
	os << "(" << v[X] << ", " << v[Y] << ", " << v[Z] << ", " << v[3] << ") ";
	return os;
}

Vec4::~Vec4(){
	delete[] v;
}


