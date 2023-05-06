#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

class Vector2 {
protected:
	double x, y;

public:
	Vector2();
	Vector2(const Vector2& v);
	Vector2(double x, double y);

	virtual double getX() const;
	virtual double getY() const;
	void setX(double x);
	void setY(double y);

	Vector2 rotate(double angle) const;

	Vector2 operator+(const Vector2& v) const;
	Vector2& operator+=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;
	Vector2& operator-=(const Vector2& v);
	Vector2 operator*(double scalar) const;
	Vector2 operator/(double scalar) const;

	friend Vector2 operator*(double scalar, const Vector2& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};

class Size : public Vector2 {
public:
	Size(double width = 0, double height = 0)
	    : Vector2(width, height) {}

	double getWidth() const { return Vector2::getX(); }
	double getHeight() const { return Vector2::getY(); }

private:
	double getX() = delete;
	double getY() = delete;
};

#endif