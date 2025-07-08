#pragma once

template<typename T>
struct Vector2
{
	T x, y;

	Vector2() = default;
	Vector2(T x, T y) : x{ x }, y{ y } {}

	Vector2 add(const Vector2% x) { return Vector2(x + v.x, y + v.y);}
};

using ivec2 = Vector2<int>;
using vec2 = Vector2<float>;