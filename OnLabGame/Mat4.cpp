#include "Mat4.h"

Mat4::Mat4(){
	m = new float[16];
	for (int i = 0; i < 16; i++)
		m[i] = 0.0f;
}

Mat4::Mat4(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44) :Mat4() {
	m[4 * 0+0] = m11;
	m[4 * 0+1] = m12;
	m[4 * 0+2] = m13;
	m[4 * 0+3] = m14;
	m[4 * 1+0] = m21;
	m[4 * 1+1] = m22;
	m[4 * 1+2] = m23;
	m[4 * 1+3] = m24;
	m[4 * 2+0] = m31;
	m[4 * 2+1] = m32;
	m[4 * 2+2] = m33;
	m[4 * 2+3] = m34;
	m[4 * 3+0] = m41;
	m[4 * 3+1] = m42;
	m[4 * 3+2] = m43;
	m[4 * 3+3] = m44;
}

Mat4::Mat4(Mat4& const other) {
	for (size_t i = 0; i < 4; i++){
		for (size_t j = 0; j < 4; j++){
			m[4 * i + j] = other.m[4 * i+j];
		}
	}
}

Mat4::Mat4(Mat4&& other) {
	m = other.m;
	other.m = nullptr;
}

void Mat4::operator=(Mat4& const other) {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			m[4 * i + j] = other.m[4 * i + j];
		}
	}
}
void Mat4::operator=(Mat4&& other) {
	if(m != nullptr)
		delete[] m;
	m = other.m;
	other.m = nullptr;
}

float& Mat4::operator()(unsigned int r, unsigned int c) {
	return m[4 * r + c];
}

Vec4 Mat4::operator*(Vec4& const v) {
	Vec4 result;
	auto sum = [&v, this](int i, int j) {
		float result = 0;
		for (size_t k = 0; k < 4; k++) {
			result += v[k] * m[4 * k + j];
		}
		return result;
	};

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			result[i] = sum(i, j);
		}
	}
	return result;
}

Mat4 Mat4::transpose()
{
	Mat4 result;
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			result.m[j * 4 + i] = m[i * 4 + j];
		}
	return result;
}

Mat4 operator*(Vec4& const v, Mat4& const m) {
	Mat4 result;
	auto sum = [&v, &m](int i, int j) {
		float result = 0;
		for (size_t k = 0; k < 4; k++) {
			result += v[i] * m(k, j);
		}
		return result;
	};

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			result(i, j) = sum(i, j);
		}
	}
	return result;
}

Mat4 operator*(Mat4& const m, Mat4& const l) {
	Mat4 result;
	auto sum = [&m, &l](int i, int j) {
		float result = 0;
		for (size_t k = 0; k < 4; k++) {
			result += m(i,k) * l(k, j);
		}
		return result;
	};

	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			result(i, j) = sum(i, j);
		}
	}
	return result;
}

ostream& operator<<(ostream& os, Mat4& m) {
	for (unsigned int i = 0; i < 4; i++){
		os << "| ";
		for (unsigned int j = 0; j < 4; j++){
			os << m(i,j) << ", ";
		}
		os << "|" << std::endl;
	}
	return os;
}



Mat4::~Mat4(){
	if (m != nullptr) {
		delete[] m;
	}
}

Mat4 Mat4::E(){
	Mat4 result(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
	return result;
}

Mat4 Mat4::Translate(Vec3& t)
{
	return Mat4(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				t[X], t[Y], t[Z], 1.0f);
}

Mat4 Mat4::Scale(Vec3& s) {
	Mat4 result(s[X], 0.0f, 0.0f, 0.0f,
				0.0f, s[Y], 0.0f, 0.0f,
				0.0f, 0.0f, s[Z], 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
	return result;
}

Mat4 Mat4::ScaleTranslate(Vec3& scale, Vec3& translate)
{
	Mat4 result(scale[X], 0.0f, 0.0f, 0.0f,
				0.0f, scale[Y], 0.0f, 0.0f,
				0.0f, 0.0f, scale[Z], 0.0f,
				translate[X], translate[Y], translate[Z], 1.0f);
	return result;
}

const float* Mat4::c_mat()
{
	return m;
}

Mat4::operator float*()
{
	return m;
}

