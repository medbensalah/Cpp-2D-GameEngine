#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Med {
	class IntroductionFMVState : public State {
	public:
		IntroductionFMVState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _city;
		Animation* _room;

		sf::Sprite _black;
		sf::Sprite _white;

		sf::Sound _roomSND;

		int alpha = 255;
		int cl = 0;
		bool cityFinished = false;
		int shade = 0;
	};
}