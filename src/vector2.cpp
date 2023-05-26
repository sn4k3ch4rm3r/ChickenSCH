#include "vector2.h"
#include <cmath>

Vector2::Vector2()
    : _x(0), _y(0) {}

Vector2::Vector2(const Vector2& other)
    : _x(other._x), _y(other._y) {}

Vector2::Vector2(double x, double y)
    : _x(x), _y(y) {}

double Vector2::getX() const {
	return _x;
}

double Vector2::getY() const {
	return _y;
}

void Vector2::setX(double x) {
	this->_x = x;
}

void Vector2::setY(double y) {
	this->_y = y;
}

const double PI = 3.14159265358979323846;
Vector2 Vector2::rotate(double angle) const {
	double rad = angle * (PI / 180);
	return Vector2(_x * cos(rad) - _y * sin(rad), _x * sin(rad) + _y * cos(rad));
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(_x + other._x, _y + other._y);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	_x += other._x;
	_y += other._y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(_x - other._x, _y - other._y);
}

Vector2& Vector2::operator-=(const Vector2& other) {
	_x -= other._x;
	_y -= other._y;
	return *this;
}

Vector2 Vector2::operator*(double scalar) const {
	return Vector2(_x * scalar, _y * scalar);
}

Vector2 operator*(double scalar, const Vector2& v) {
	return v * scalar;
}

Vector2 Vector2::operator/(double scalar) const {
	return Vector2(_x / scalar, _y / scalar);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
	os << "Vector2(" << v._x << ", " << v._y << ")";
	return os;
}