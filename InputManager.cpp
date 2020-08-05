#include "InputManager.hpp"

namespace Med {
	bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window, sf::Event& e) {
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (e.type == sf::Event::MouseButtonReleased && tempRect.contains(sf::Mouse::getPosition(window))) {
			if (e.mouseButton.button == button)
				return true;
		}

		return false;
	}
	sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window) {
		return sf::Mouse::getPosition(window);
	}
}