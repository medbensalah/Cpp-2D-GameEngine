#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"
#include "DigimonSelectionState.hpp"

namespace Med {
	class LoginState : public State {
	public:
		LoginState(GameDataRef data);

		void init();
		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _backGround;
		sf::Sprite _gate;
		sf::Sprite _A;
		sf::Sprite _B;
		sf::Sprite _C;
		sf::Sprite _D;
		sf::Sprite _E;
		sf::Sprite _F;
		sf::Sprite _G;
		sf::Sprite _H;
		sf::Sprite _I;
		sf::Sprite _J;
		sf::Sprite _K;
		sf::Sprite _L;
		sf::Sprite _M;
		sf::Sprite _N;
		sf::Sprite _O;
		sf::Sprite _P;
		sf::Sprite _Q;
		sf::Sprite _R;
		sf::Sprite _S;
		sf::Sprite _T;
		sf::Sprite _U;
		sf::Sprite _V;
		sf::Sprite _W;
		sf::Sprite _X;
		sf::Sprite _Y;
		sf::Sprite _Z;
		sf::Sprite _confirm;
		sf::Sprite _del;

		sf::Sprite _hover;

		sf::Text _name;
		sf::Text _request;
		
		sf::Sound _gateEffects;

		sf::Sound _click;
	};
}