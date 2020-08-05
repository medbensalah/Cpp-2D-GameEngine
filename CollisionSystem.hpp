#pragma once

#include <SFML/Graphics.hpp>
#include "ECS.hpp"

namespace Med {
	class CollisionSystem : public System {
	public:
		void init(Entity& entity);
		void update(float dt);
		void draw(sf::RenderWindow& window);
		int indexX;
		int indexY;
		PlayerComponent* pc;
		TransformComponent* tc;
		sf::RectangleShape player;
	};
}