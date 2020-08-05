#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Med {
	class MainMenuState : public State {
	public:
		MainMenuState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _backGround;
		sf::Sprite _newGameButton;
		sf::Sprite _loadGameButton;
		sf::Sprite _title;

		sf::Sound _click;
	};
}