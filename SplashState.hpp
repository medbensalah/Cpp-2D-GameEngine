#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Med {
	class SplashState : public State {
	public:
		SplashState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;
		sf::Sprite _background;
		sf::Sprite _black;
	};
}