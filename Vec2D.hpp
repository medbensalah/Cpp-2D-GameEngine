#pragma once

#include <cassert>

class Vec2D {
public:
	float x;
	float y;
	
	Vec2D() {
		x = y = 0.0f;
	}
	Vec2D(float a, float b) :x(a), y(b) {}

	Vec2D operator*(float const& k) {
		return Vec2D(x * k, y * k);
	}
	Vec2D& operator*=(float const& k) {
		x = x * k;
		y = y * k;

		return *this;
	}
	Vec2D operator/(float const& k) {
		assert(k && "Can't divide by 0");
		return Vec2D(x / k, y / k);
	}
	Vec2D& operator/=(float const& k) {
		assert(k && "Can't divide by 0");
		x = x / k;
		y = y / k;

		return *this;
	}

	Vec2D operator+(Vec2D const& v) {
		return Vec2D(x + v.x, y + v.y);
	}
	Vec2D& operator+=(Vec2D const& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vec2D operator-(Vec2D const& v) {
		return Vec2D(x - v.x, y - v.y);
	}
	Vec2D& operator-=(Vec2D const& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	float operator*(Vec2D const& v) {
		return x * v.x + y * v.y;
	}
};