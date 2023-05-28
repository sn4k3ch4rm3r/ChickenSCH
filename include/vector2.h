#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>

/// @brief 2 dimenziós vekor osztály.
class Vector2 {
public:
	Vector2();
	Vector2(const Vector2& v);
	Vector2(double x, double y);

	virtual double getX() const;
	virtual double getY() const;

	/// @brief Vektor forgatása.
	/// @param angle Forgatás szöge fokokban
	/// @return Adott szöggel elforgatott vektor.
	Vector2 rotate(double angle) const;

	/// @brief Vektorok összeadása.
	/// @param v A másik vektor.
	/// @return Új vektor, ami az eredeti két vektor összege.
	Vector2 operator+(const Vector2& v) const;

	/// @brief Vektor hozzáadása az eredeti vektorhoz.
	/// @param v A másik vektor.
	/// @return Referencia az eredeti vektorra.
	Vector2& operator+=(const Vector2& v);

	/// @brief Vektorok kivonása.
	/// @param v A másik vektor.
	/// @return Új vektor, ami az eredeti két vektor különbsége.
	Vector2 operator-(const Vector2& v) const;

	/// @brief Vektor kivonása az eredeti vektorból.
	/// @param v A másik vektor.
	/// @return Referencia az eredeti vektorra.
	Vector2& operator-=(const Vector2& v);

	/// @brief Vektor skalárral való szorzása.
	/// @param scalar A skalár.
	/// @return Új vektor, ami az eredeti vektor skalár szorosa.
	Vector2 operator*(double scalar) const;

	/// @brief Vektor skalárral való osztása.
	/// @param scalar A skalár.
	/// @return Új vektor, ami az eredeti vektor skalárral elosztva.
	Vector2 operator/(double scalar) const;

	/// @brief Vektor skalárral való szorzása jobbról.
	/// @param scalar A skalár.
	/// @param v A vektor.
	/// @return Új vektor, ami az eredeti vektor skalár szorosa.
	friend Vector2 operator*(double scalar, const Vector2& v);

	/// @brief Vektor kiíró operátora.
	friend std::ostream& operator<<(std::ostream& os, const Vector2& v);

private:
	double _x;
	double _y;
};

/// @brief Alias a Vector2 osztályból méret megadására.
class Size : public Vector2 {
public:
	explicit Size(double width = 0, double height = 0)
	    : Vector2(width, height) {}

	// getX és getY helyett getWidth és getHeight függvényeket definiálunk.
	double getWidth() const { return Vector2::getX(); }
	double getHeight() const { return Vector2::getY(); }

private:
	//Az eredeti getX és getY függvényeket elrejtjük, hogy ne lehessen őket használni.
	double getX() = delete;
	double getY() = delete;
};

#endif