#include "vector2.h"

Vector2::Vector2()
    : x(0), y(0) {}

Vector2::Vector2(const Vector2& other)
    : x(other.x), y(other.y) {}

Vector2::Vector2(double x, double y)
    : x(x), y(y) {}

double Vector2::getX() const {
	return x;
}

double Vector2::getY() const {
	return y;
}

Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2& Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2 Vector2::operator*(double scalar) const {
	return Vector2(x * scalar, y * scalar);
}

Vector2 operator*(double scalar, const Vector2& v) {
	return v * scalar;
}

Vector2 Vector2::operator/(double scalar) const {
	return Vector2(x / scalar, y / scalar);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
	os << "Vector2(" << v.x << ", " << v.y << ")";
	return os;
}