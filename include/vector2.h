#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

class Vector2 {
private:
	double x, y;

public:
	Vector2();
	Vector2(const Vector2& v);
	Vector2(double x, double y);

	double getX() const;
	double getY() const;

	Vector2 operator+(const Vector2& v) const;
	Vector2& operator+=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;
	Vector2& operator-=(const Vector2& v);
	Vector2 operator*(double scalar) const;

	friend Vector2 operator*(double scalar, const Vector2& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

#endif