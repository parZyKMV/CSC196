#pragma once
#include <stdlib.h>

namespace viper {
	namespace random {
		int getRandom() { return rand(); }

		int getRandomInt(int max) { return rand() % max; }


		int getRandomInt(int min, int max) { return min + getRandomInt(max - min + 1); }

		inline float getRandomFloat() { return rand() / RAND_MAX; }
	}
}
