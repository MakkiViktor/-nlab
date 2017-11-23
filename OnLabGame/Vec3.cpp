#include "Vec3.h"

Vec3::Vec3()
{
	v = new float[3];
}

Vec3::Vec3(float x, float y, float z):Vec3() {
	v[X] = x; v[Y] = y; v[Z] = z;
}

Vec3::Vec3(Vec3& const other): Vec3() {
	v[X] = other[X];
	v[Y] = other[Y];
	v[Z] = other[Z];
}
Vec3::Vec3(Vec3&& other) {
	v = other.v;
	other.v = nullptr;
}
void Vec3::operator=(Vec3& const other) {
	v[X] = other[X];
	v[Y] = other[Y];
	v[Z] = other[Z];
}

void Vec3::operator=(Vec3&& other) {
	v = other.v;
	other.v = nullptr;
}

float& Vec3::operator[](unsigned int index){
	return v[index];
}

Vec3 Vec3::operator+(Vec3& const u) {
	Vec3 result;
	result[X] = v[X] + u[X];
	result[Y] = v[Y] + u[Y];
	result[Z] = v[Z] + u[Z];
	return result;
}
Vec3 Vec3::operator-(Vec3& const u) {
	Vec3 result;
	result[X] = v[X] - u[X];
	result[Y] = v[Y] - u[Y];
	result[Z] = v[Z] - u[Z];
	return result;
}
Vec3 Vec3::cross(Vec3& const u) {
	Vec3 result;
	result[X] = v[Y] * u[Z] - v[Z] * u[Y];
	result[Y] = v[Z] * u[X] - v[X] * u[Z];
	result[Z] = v[X] * u[Y] - v[Y] * u[X];
	return result;
}

Vec3 Vec3::operator*(float s) {
	Vec3 result;
	result[X] = v[X] * s;
	result[Y] = v[Y] * s;
	result[Z] = v[Z] * s;
	return result;
}
float Vec3::dot(Vec3& const u) {
	float result = v[X] * u[X] + v[Y] * u[Y] + v[Z] * u[Z];
	return result;
}

float Vec3::magnitude() {
	float result = sqrt(pow(v[X], 2) + pow(v[Y], 2) + pow(v[Z], 2));
	return result;
}

Vec3 Vec3::normalize()
{
	float d = magnitude();
	return Vec3(v[X] / d, v[Y] / d, v[Z] / d);
}

float Vec3::cos(Vec3& const u) {
	float cos = dot(u) / magnitude() * u.magnitude();
	return cos;
}

float & Vec3::x()
{
	return v[X];
}

float & Vec3::y()
{
	return v[Y];
}

float & Vec3::z()
{ 
	return v[Z];
}

float Vec3::alpha(Vec3& const u) {
	return acosf(cos(u));
}

ostream & Vec3::operator<<(ostream & os){
	os << "(" << v[X] << ", " << v[Y] << ", " << v[Z] << ", " << v[3] << ") ";
	return os;
}

Vec3::~Vec3(){
	delete[] v;
}


