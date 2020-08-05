#pragma once

#include <SFML/Graphics.hpp>

namespace Med {
	class InputManager {
	public:
		InputManager() {}
		~InputManager() {}

		bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window,sf::Event& e);
		sf::Vector2i getMousePosition(sf::RenderWindow& window);

	};
}