#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "ECS.hpp"

namespace Med {
	class CombatState : public State {
	public:
		CombatState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;
	};
}