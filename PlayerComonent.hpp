#pragma once

#include <SFML/Graphics.hpp>

namespace Med {

	struct PlayerComponent {
		int sizeX;
		int sizeY;
		float scaleX;
		float scaleY;
		sf::Text name;;
		int digimon;
		sf::Texture tex;
		float steps;
		int bits;
//		std::vector<DigimonComponent> digimon;
	};
}