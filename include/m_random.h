#ifndef M_RANDOM_H
#define M_RANDOM_H

#include <cstdlib>
#include <ctime>

/// @brief Random számok generálását leegyszerűsítő osztály.
class Random {
public:
	/// @brief A random szám generátor inicializálása.
	/// @param seed A random szám generátor seed-je.
	static void seed(int seed = std::time(nullptr)) {
		srand(seed);
	}

	/// @brief Random integer generálása a megadott intervallumban.
	/// @param min Minimum érték.
	/// @param max Maximum érték.
	/// @return Random szám min és max között.
	inline static int randInt(int min, int max) {
		return rand() % (max - min + 1) + min;
	}

	/// @brief Random bool generálása a megadott valószínűséggel.
	/// @param probability A true érték valószínűsége.
	/// @return Random bool.
	inline static bool randBool(double probability = 0.5) {
		return (double)rand() / RAND_MAX < probability;
	}

	/// @brief Random double generálása a megadott intervallumban.
	/// @param min Minimum érték.
	/// @param max Maximum érték.
	/// @return Random szám min és max között.
	inline static double randDouble(double min, double max) {
		return (double)rand() / RAND_MAX * (max - min) + min;
	}
};

#endif