#pragma once

#include <SFML/Graphics.hpp>
#include "ECS.hpp"
#include "Animation.hpp"
#include <iostream>
#include <random>


namespace Med {
	enum dir { S = 0, U, UR, R, BR, B, BL, L, UL, X};

	class PlayerSystem : public System {
	public:

		PlayerSystem() : distribution(1, 100),
			engine(rd()) {}
		void init(Entity& entity);
		void handleInput(sf::Event& event);
		void update(float dt);
		void draw(sf::RenderWindow& window);
		bool battle(float dt);
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
		int prob;

		std::random_device rd;
		std::uniform_int_distribution<int> distribution;
		std::mt19937 engine;
	};
}
