#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace Med {
	class DigimonSelectionState : public State {
	public:
		DigimonSelectionState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _gate;
		sf::Sprite _confirm;
		sf::Sprite _backGround;

		sf::Sprite _box1;
		sf::Sprite _box2;
		sf::Sprite _box3;
		sf::Sprite _hoverBox;

		Animation* _terriermon;
		Animation* _veemon;
		Animation* _impmon;
		Animation* _terriermonS;
		Animation* _veemonS;
		Animation* _impmonS;

		sf::Clock _typeClock;

		int _textChar = 0;
		std::string _request = "Welcome " + playerName.getString() + ".\nSelect your digimon:  ";
		sf::Text _requestText;

		int _TDChar = 0;
		std::string _TDescription = "Terriermon: good healer and excells at support skills.  ";
		sf::Text _TDescriptionText;
		int _VDChar = 0;
		std::string _VDescription = "Veemon: a balanced character for new players.  ";
		sf::Text _VDescriptionText;
		int _IDChar = 0;
		std::string _IDescription = "Impmon: a heavy striker, good at both magic and physical attacks.";
		sf::Text _IDescriptionText;

		sf::Sound _gateEffects;
		sf::Sound _typing;
		sf::Sound _click;
	};
}