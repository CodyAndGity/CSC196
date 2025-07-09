#pragma once
#include "Math.h"
#include <cassert>
namespace bonzai {
	template<typename T>

	struct Vector2 {
		T x, y;
		Vector2() = default;
		Vector2(T x, T y) : x(x), y(y) {}

			//return (index == 0) ? x : y; }
		T operator [] (unsigned int index) const {assert(index < 2);  return (&x)[index];}
		T& operator [] (unsigned int index) {assert(index < 2);  return (&x)[index];}

		Vector2 operator+(const Vector2& value) const { return Vector2{ x + value.x,y + value.y }; }
		Vector2 operator-(const Vector2& value) const { return Vector2{ x - value.x,y - value.y }; }
		Vector2 operator*(const Vector2& value) const { return Vector2{ x * value.x,y * value.y }; }
		Vector2 operator/(const Vector2& value) const { return Vector2{ x / value.x,y / value.y }; }

		Vector2 operator+(float value) const { return Vector2{ x + value,y + value }; }
		Vector2 operator-(float value) const { return Vector2{ x - value,y - value }; }
		Vector2 operator*(float value) const { return Vector2{ x * value,y * value }; }
		Vector2 operator/(float value) const { return Vector2{ x / value,y / value }; }

		Vector2& operator+=(const Vector2& value) { x += value.x; y += value.y; return *this; }
		Vector2& operator-=(const Vector2& value) { x -= value.x; y -= value.y; return *this; }
		Vector2& operator*=(const Vector2& value) { x *= value.x; y *= value.y; return *this; }
		Vector2& operator/=(const Vector2& value) { x /= value.x; y /= value.y; return *this; }

		Vector2& operator+=(float value) {  x += value; y += value; return *this ; }
		Vector2& operator-=(float value) {  x -= value; y -= value; return *this ; }
		Vector2& operator*=(float value) {  x *= value; y *= value; return *this ; }
		Vector2& operator/=(float value) { x /= value; y /= value; return *this ; }

		/// <summary>
		/// Calculates the squared length (magnitude) of a vector.
		/// </summary>
		/// <returns>The sum of the squares of the vector's x and y components.</returns>
		float lengthSquared() { return x * x + y * y; }

		/// <summary>
		/// Calculates the length (magnitude) of a vector.
		/// </summary>
		/// <returns>The length of the vector as a floating-point value.</returns>
		float length() { return math::sqrtf(lengthSquared()); }
	};
	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}