#include "Vec3.h"

Vec3::Vec3()
{
	v = new float[3];
}

Vec3::Vec3(float x, float y, float z):Vec3() {
	v[X] = x; v[Y] = y; v[Z] = z;
}

Vec3::Vec3(const Vec3& other): Vec3() {
	v[X] = other.v[X];
	v[Y] = other.v[Y];
	v[Z] = other.v[Z];
}
Vec3::Vec3(Vec3&& other) {
	v = other.v;
	other.v = nullptr;
}
void Vec3::operator=(const Vec3& other) {
	v[X] = other.v[X];
	v[Y] = other.v[Y];
	v[Z] = other.v[Z];
}

void Vec3::operator=(Vec3&& other) {
	if (v != nullptr)
		delete[] v;
	v = other.v;
	other.v = nullptr;
}

//float& Vec3::operator[](unsigned int index){
//	return v[index];
//}

Vec3 Vec3::operator+(const Vec3& u) {
	Vec3 result;
	result.v[X] = v[X] + u.v[X];
	result.v[Y] = v[Y] + u.v[Y];
	result.v[Z] = v[Z] + u.v[Z];
	return result;
}
Vec3 Vec3::operator-(const Vec3& u) {
	Vec3 result;
	result.v[X] = v[X] - u.v[X];
	result.v[Y] = v[Y] - u.v[Y];
	result.v[Z] = v[Z] - u.v[Z];
	return result;
}
Vec3 Vec3::cross(const Vec3& u) {
	Vec3 result;
	result.v[X] = v[Y] * u.v[Z] - v[Z] * u.v[Y];
	result.v[Y] = v[Z] * u.v[X] - v[X] * u.v[Z];
	result.v[Z] = v[X] * u.v[Y] - v[Y] * u.v[X];
	return result;
}

Vec3 Vec3::operator*(float s) {
	Vec3 result;
	result.v[X] = v[X] * s;
	result.v[Y] = v[Y] * s;
	result.v[Z] = v[Z] * s;
	return result;
}
float Vec3::dot(const Vec3& u) {
	float result = v[X] * u.v[X] + v[Y] * u.v[Y] + v[Z] * u.v[Z];
	return result;
}

float Vec3::magnitude() const{
	float result = sqrt(pow(v[X], 2) + pow(v[Y], 2) + pow(v[Z], 2));
	return result;
}

Vec3 Vec3::normalize()
{
	float d = magnitude();
	return Vec3(v[X] / d, v[Y] / d, v[Z] / d);
}

float Vec3::cos(const Vec3& u) {
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

float Vec3::alpha(const Vec3& u) {
	return acosf(cos(u));
}

Vec3::operator float*()
{
	return v;
}

ostream & operator<<(ostream & os, Vec3& v){
	os << "(" << v[X] << ", " << v[Y] << ", " << v[Z] << ", " << v[3] << ") ";
	return os;
}

Vec3::~Vec3(){
	if(v != nullptr)
		delete[] v;
}


