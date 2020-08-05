#pragma once

#include <SFML/Graphics.hpp>
#include "ECS.hpp"
#include "Animation.hpp"
#include <iostream>


namespace Med {
	enum dir { S = 0, U, UR, R, BR, B, BL, L, UL, X};

	class PlayerSystem : public System {
	public:
		void init(Entity& entity);
		void handleInput(sf::Event& event);
		void update(float dt);
		void draw(sf::RenderWindow& window);
		int indexX;
		int indexY;
		PlayerComponent* pc;
		TransformComponent* tc;
		Animation player;
		Animation idle;
		Animation* anim;
		sf::CircleShape shadow;
		dir dd;
		dir ds;
		sf::Clock clk;
	};
}
