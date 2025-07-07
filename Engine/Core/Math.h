#pragma once
#include <algorithm>

namespace viper {
	constexpr float pi = 3.14;
	constexpr float twoPi = 2 * pi;
	constexpr float halfPi = pi / 2;

	constexpr float redToDeg(float red) { return red * (180 / pi); }
	constexpr float deegToRef(float deg) { return deg * (pi/180); }


	using std::min;
	using std::max;
	//using std::clamp;
	/*template <typename T>
	T min(T a, T b) {
		return std::min(a, b);
	}*/

	
}