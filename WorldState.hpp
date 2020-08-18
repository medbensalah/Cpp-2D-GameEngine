#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "ECS.hpp"
#include "PlayerSystem.hpp"
#include "CollisionSystem.hpp"

namespace Med {
	class WorldState : public State {
	public:
		WorldState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;
		Entity player;
		std::shared_ptr<CollisionSystem> collisionSystem;
		sf::View camera;
	};
}