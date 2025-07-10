#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace viper {
	namespace math {
		constexpr float pi = 3.14;
		constexpr float	twoPi = pi * 2;
		constexpr float halfPi = pi / 2;

		constexpr float radToDeg(float rad) { return rad * (100 / pi); }

		constexpr float degtoRad(float deg) { return deg * (pi / 100); }

		using std::min;
		using std::max;
		//using std::clamp;
		using std::sqrt;
		using std::sqrtf;
		using std::sin;
		using std::sinf;
		using std::cos;
		using std::cosf;
	}
}
