#ifndef M_RANDOM_H
#define M_RANDOM_H

#include <cstdlib>
#include <ctime>

class Random {
public:
	static void seed(int seed = std::time(nullptr)) {
		srand(seed);
	}
	inline static int randInt(int min, int max) {
		return rand() % (max - min + 1) + min;
	}
	inline static bool randBool(double probability = 0.5) {
		return (double)rand() / RAND_MAX < probability;
	}
};

#endif