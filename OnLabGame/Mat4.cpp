#include "Mat4.h"



Mat4::Mat4(){
	m = new float*[4];
	for (size_t i = 0; i < 4; i++){
		m[i] = new float[4];
	}
}

Mat4::Mat4(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44) {
	m[0][0] = m11;
	m[0][1] = m12;
	m[0][2] = m13;
	m[0][3] = m14;
	m[1][0] = m21;
	m[1][1] = m22;
	m[1][2] = m23;
	m[1][3] = m24;
	m[2][0] = m31;
	m[2][1] = m32;
	m[2][2] = m33;
	m[2][3] = m34;
	m[3][0] = m41;
	m[3][1] = m42;
	m[3][2] = m43;
	m[3][3] = m44;
}

Mat4::Mat4(Mat4& const other) {
	for (size_t i = 0; i < 4; i++){
		for (size_t j = 0; j < 4; j++){
			m[i][j] = other.m[i][j];
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
			m[i][j] = other.m[i][j];
		}
	}
}
void Mat4::operator=(Mat4&& other) {
	m = other.m;
	other.m = nullptr;
}

float& Mat4::operator()(unsigned int r, unsigned int c) {
	return m[r][c];
}

Vec4& Mat4::operator*(Vec4& const v) {
	Vec4 result;
	auto sum = [&v, this](int i, int j) {
		float result = 0;
		for (size_t k = 0; k < 4; k++) {
			result += v[k] * m[k][j];
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

Mat4& operator*(Vec4& const v, Mat4& const m) {
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

Mat4& operator*(Mat4& const m, Mat4& const l) {
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

ostream& Mat4::operator<<(ostream& os) {
	for (size_t i = 0; i < 4; i++){
		os << "| ";
		for (size_t j = 0; j < 4; j++){
			os << m[i][j] << ", ";
		}
		os << "|" << std::endl;
	}
}

Mat4 & Mat4::E(){
	Mat4 result(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
	return result;
}


Mat4::~Mat4(){
	for (size_t i = 0; i < 4; i++){
		delete[] m[i];
	}
	delete[] m;
}

