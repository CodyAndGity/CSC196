#pragma once
#include <SDL3/SDL.h>
#include <algorithm>
#include <cmath>

namespace bonzai::math {
	
	constexpr float pi = 3.14159265358979323846f;
	constexpr float twoPi = 2.0f * pi;
	constexpr float halfPi = 0.5f * pi;
	/// <summary>
	/// Converts an angle from radians to degrees.
	/// </summary>
	/// <param name="radians">The angle in radians to convert.</param>
	/// <returns>The equivalent angle in degrees.</returns>
	constexpr float radToDeg(float radians) { return radians * (180.0f / pi); }
	/// <summary>
	/// Converts an angle from degrees to radians.
	/// </summary>
	/// <param name="degrees">The angle in degrees to convert.</param>
	/// <returns>The angle in radians.</returns>
	constexpr float degToReg(float degrees) { return degrees * (pi / 180.0f); }


	constexpr int wrap(int value, int min, int max) {
		int range = max - min;
		int result = (value - min) % range;
		if (result < 0) {
			result += range;
		}
		return result + min;
	}
	inline float wrap(float value, float min, float max) {
		float range = max - min;
		float result = std::fmod(value - min, range);
		if (result < 0) {
			result += range;
		}
		return result + min;
	}


	//*pirate music plays*
	using std::min;
	using std::max;
	using std::clamp;
	using std::sqrt;
	using std::sqrtf;
	using std::sin;
	using std::sinf;
	using std::cos;
	using std::cosf;
	using std::atan2;
	using std::atanf;
	using std::atan2f;
	using std::abs;
	using std::fabs;
	
}