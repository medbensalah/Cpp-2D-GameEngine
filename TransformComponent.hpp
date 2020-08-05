#pragma once

#include "Vec2D.hpp"
namespace Med {
	struct TransformComponent {
		Vec2D position;
		Vec2D velocity;
		Vec2D acceleration;
	};
}