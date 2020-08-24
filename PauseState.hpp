#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "ECS.hpp"
#include "PlayerSystem.hpp"
#include "CollisionSystem.hpp"

namespace Med {
	class PauseState : public State {
	public:
		PauseState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _backgroundI;
		sf::Sprite item0;
		sf::Sprite item1;
		sf::Sprite item2;
		sf::Sprite item3;
		sf::Sprite item4;
		sf::Sprite item5;
		sf::Sprite item6;
		sf::Sprite item7;
		sf::Sprite item8;
		sf::Sprite _bits;
		//TODO
//		sf::Sprite _area;
		std::map<int, sf::Sprite> _menuItems{
			{0, item0},
			{1, item1},
			{2, item2},
			{3, item3},
			{4, item4},
			{5, item5},
			{6, item6},
			{7, item7},
			{8, item8},
		};
		int _shown;
		int _shownItems;
		int _selected;
	};
}