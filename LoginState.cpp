#include "LoginState.hpp"
#include "DigimonSelectionState.hpp"
#include <sstream>
#include <iostream>
#include <Windows.h>

sf::Text playerName;

namespace Med {
	LoginState::LoginState(GameDataRef data) : _data(data) {}

	void LoginState::init() {
		this->_data->assets.loadTexture("Login Background", LOGIN_SCENE_BACKGROUND);
		this->_data->assets.loadTexture("Login Gate", LOGIN_SCENE_LOGIN_GATE);
		this->_data->assets.loadTexture("Login Confirm Button", LOGIN_SCENE_INPUT_CONFIRM_BUTTON);
		this->_data->assets.loadTexture("Login Del Button", LOGIN_SCENE_INPUT_DEL_BUTTON);
		this->_data->assets.loadTexture("Hover", LOGIN_SCENE_INPUT_HOVER);
		this->_data->assets.loadTexture("Login A", LOGIN_SCENE_INPUT_A);
		this->_data->assets.loadTexture("Login B", LOGIN_SCENE_INPUT_B);
		this->_data->assets.loadTexture("Login C", LOGIN_SCENE_INPUT_C);
		this->_data->assets.loadTexture("Login D", LOGIN_SCENE_INPUT_D);
		this->_data->assets.loadTexture("Login E", LOGIN_SCENE_INPUT_E);
		this->_data->assets.loadTexture("Login F", LOGIN_SCENE_INPUT_F);
		this->_data->assets.loadTexture("Login G", LOGIN_SCENE_INPUT_G);
		this->_data->assets.loadTexture("Login H", LOGIN_SCENE_INPUT_H);
		this->_data->assets.loadTexture("Login I", LOGIN_SCENE_INPUT_I);
		this->_data->assets.loadTexture("Login J", LOGIN_SCENE_INPUT_J);
		this->_data->assets.loadTexture("Login K", LOGIN_SCENE_INPUT_K);
		this->_data->assets.loadTexture("Login L", LOGIN_SCENE_INPUT_L);
		this->_data->assets.loadTexture("Login M", LOGIN_SCENE_INPUT_M);
		this->_data->assets.loadTexture("Login N", LOGIN_SCENE_INPUT_N);
		this->_data->assets.loadTexture("Login O", LOGIN_SCENE_INPUT_O);
		this->_data->assets.loadTexture("Login P", LOGIN_SCENE_INPUT_P);
		this->_data->assets.loadTexture("Login Q", LOGIN_SCENE_INPUT_Q);
		this->_data->assets.loadTexture("Login R", LOGIN_SCENE_INPUT_R);
		this->_data->assets.loadTexture("Login S", LOGIN_SCENE_INPUT_S);
		this->_data->assets.loadTexture("Login T", LOGIN_SCENE_INPUT_T);
		this->_data->assets.loadTexture("Login U", LOGIN_SCENE_INPUT_U);
		this->_data->assets.loadTexture("Login V", LOGIN_SCENE_INPUT_V);
		this->_data->assets.loadTexture("Login W", LOGIN_SCENE_INPUT_W);
		this->_data->assets.loadTexture("Login X", LOGIN_SCENE_INPUT_X);
		this->_data->assets.loadTexture("Login Y", LOGIN_SCENE_INPUT_Y);
		this->_data->assets.loadTexture("Login Z", LOGIN_SCENE_INPUT_Z);

		this->_data->assets.loadFont("bookos", "Resources/fonts/bookos.ttf");

		this->_data->assets.loadSoundBuffer("Gate", LOGIN_SCENE_GATE_AFX_FILEPATH);

		this->_backGround.setTexture(this->_data->assets.getTexture("Login Background"));
		this->_gate.setTexture(this->_data->assets.getTexture("Login Gate"));
		this->_gate.setTextureRect(sf::IntRect(0, 0, 1280, 663));
		this->_confirm.setTexture(this->_data->assets.getTexture("Login Confirm Button"));
		this->_del.setTexture(this->_data->assets.getTexture("Login Del Button"));
		this->_A.setTexture(this->_data->assets.getTexture("Login A"));
		this->_B.setTexture(this->_data->assets.getTexture("Login B"));
		this->_C.setTexture(this->_data->assets.getTexture("Login C"));
		this->_D.setTexture(this->_data->assets.getTexture("Login D"));
		this->_E.setTexture(this->_data->assets.getTexture("Login E"));
		this->_F.setTexture(this->_data->assets.getTexture("Login F"));
		this->_G.setTexture(this->_data->assets.getTexture("Login G"));
		this->_H.setTexture(this->_data->assets.getTexture("Login H"));
		this->_I.setTexture(this->_data->assets.getTexture("Login I"));
		this->_J.setTexture(this->_data->assets.getTexture("Login J"));
		this->_K.setTexture(this->_data->assets.getTexture("Login K"));
		this->_L.setTexture(this->_data->assets.getTexture("Login L"));
		this->_M.setTexture(this->_data->assets.getTexture("Login M"));
		this->_N.setTexture(this->_data->assets.getTexture("Login N"));
		this->_O.setTexture(this->_data->assets.getTexture("Login O"));
		this->_P.setTexture(this->_data->assets.getTexture("Login P"));
		this->_Q.setTexture(this->_data->assets.getTexture("Login Q"));
		this->_R.setTexture(this->_data->assets.getTexture("Login R"));
		this->_S.setTexture(this->_data->assets.getTexture("Login S"));
		this->_T.setTexture(this->_data->assets.getTexture("Login T"));
		this->_U.setTexture(this->_data->assets.getTexture("Login U"));
		this->_V.setTexture(this->_data->assets.getTexture("Login V"));
		this->_W.setTexture(this->_data->assets.getTexture("Login W"));
		this->_X.setTexture(this->_data->assets.getTexture("Login X"));
		this->_Y.setTexture(this->_data->assets.getTexture("Login Y"));
		this->_Z.setTexture(this->_data->assets.getTexture("Login Z"));

		this->_hover.setTexture(this->_data->assets.getTexture("Hover"));
		this->_hover.setPosition(1280, 663);

		this->_name.setFont(this->_data->assets.getFont("bookos"));
		this->_request.setFont(this->_data->assets.getFont("bookos"));
		this->_name.setCharacterSize(42);
		this->_request.setCharacterSize(30);
		this->_name.setLetterSpacing(5);
		this->_request.setLetterSpacing(5);
		this->_name.setPosition(755, 110);
		this->_request.setPosition(40, 50);
		this->_request.setString("Enter your name: ");


		this->_gateEffects.setBuffer(this->_data->assets.getSoundBuffer("Gate"));
		this->_click.setBuffer(this->_data->assets.getSoundBuffer("Click"));
		this->_gateEffects.setPlayingOffset(sf::milliseconds(700));

		this->_A.setPosition(64, 120);
		this->_B.setPosition(192, 120);
		this->_C.setPosition(320, 120);
		this->_D.setPosition(448, 120);
		this->_E.setPosition(128, 180);
		this->_F.setPosition(256, 180);
		this->_G.setPosition(384, 180);
		this->_H.setPosition(512, 180);
		this->_I.setPosition(64, 240);
		this->_J.setPosition(192, 240);
		this->_K.setPosition(320, 240);
		this->_L.setPosition(448, 240);
		this->_M.setPosition(128, 300);
		this->_N.setPosition(256, 300);
		this->_O.setPosition(384, 300);
		this->_P.setPosition(512, 300);
		this->_Q.setPosition(64, 360);
		this->_R.setPosition(192, 360);
		this->_S.setPosition(320, 360);
		this->_T.setPosition(448, 360);
		this->_U.setPosition(128, 420);
		this->_V.setPosition(256, 420);
		this->_W.setPosition(384, 420);
		this->_X.setPosition(512, 420);
		this->_Y.setPosition(64, 480);
		this->_Z.setPosition(192, 480);
		this->_confirm.setPosition(1080, 540);
		this->_del.setPosition(448, 480);

		this->_data->assets._bgm.stop();

		this->_data->assets._bgm.openFromFile(LOGIN_BGM);
		this->_data->assets._bgm.setLoop(true);
		this->_data->assets._bgm.play();
	}


	std::string name;

	bool closingGate = false;

	void LoginState::handleInput() {
		sf::Event e;
		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
			if (name.length() <= 6) {
				if (this->_data->input.isSpriteClicked(this->_A, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "A";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_B, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "B";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_C, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "C";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_D, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "D";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_E, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "E";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_F, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "F";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_G, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "G";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_H, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "H";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_I, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "I";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_J, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "J";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_K, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "K";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_L, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "L";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_M, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "M";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_N, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "N";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_O, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "O";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_P, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "P";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_Q, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "Q";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_R, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "R";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_S, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "S";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_T, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "T";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_U, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "U";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_V, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "V";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_W, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "W";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_X, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "X";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_Y, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "Y";
					this->_name.setString(name);
				}
				if (this->_data->input.isSpriteClicked(this->_Z, sf::Mouse::Left, this->_data->window, e)) {
					this->_click.play();
					name += "Z";
					this->_name.setString(name);
				}
			}
			if (this->_data->input.isSpriteClicked(this->_del, sf::Mouse::Left, this->_data->window, e)) {
				if (name.length()) {
					this->_click.play();
					name.erase(name.length() - 1);
					this->_name.setString(name);
				}
			}
			if (this->_data->input.isSpriteClicked(this->_confirm, sf::Mouse::Left, this->_data->window, e)) {
				playerName.setString(name);
				if (this->_gate.getTextureRect().left == 12800 && name.length()) {
					this->_click.play();
					closingGate = true;
				}
			}
		}
	}

	sf::Clock clk;
	int c = 1100;

	void LoginState::update(float dt) {
		if (static_cast<int>(clk.getElapsedTime().asMilliseconds()) - c > 20) {
			if (this->_gate.getTextureRect().left != 12800 && !closingGate) {
				if (this->_gate.getTextureRect().left == 0) {
					_gateEffects.play();
				}
				this->_gate.setTextureRect(sf::IntRect(this->_gate.getTextureRect().left + 1280, 0, 1280, 663));
				c = static_cast<int>(clk.getElapsedTime().asMilliseconds());
			}
			else if (this->_gate.getTextureRect().left != 0 && closingGate) {
				if (this->_gate.getTextureRect().left == 12800) {
					_gateEffects.setPlayingOffset(sf::milliseconds(500));
					_gateEffects.play();
				}
				this->_gate.setTextureRect(sf::IntRect(this->_gate.getTextureRect().left - 1280, 0, 1280, 663));
				c = static_cast<int>(clk.getElapsedTime().asMilliseconds());

			}
		}

		if (this->_A.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_A.getPosition());
		}
		else if (this->_B.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_B.getPosition());
		}
		else if (this->_C.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_C.getPosition());
		}
		else if (this->_D.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_D.getPosition());
		}
		else if (this->_E.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_E.getPosition());
		}
		else if (this->_F.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_F.getPosition());
		}
		else if (this->_G.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_G.getPosition());
		}
		else if (this->_H.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_H.getPosition());
		}
		else if (this->_I.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_I.getPosition());
		}
		else if (this->_J.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_J.getPosition());
		}
		else if (this->_K.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_K.getPosition());
		}
		else if (this->_L.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_L.getPosition());
		}
		else if (this->_M.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_M.getPosition());
		}
		else if (this->_N.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_N.getPosition());
		}
		else if (this->_O.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_O.getPosition());
		}
		else if (this->_P.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_P.getPosition());
		}
		else if (this->_Q.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_Q.getPosition());
		}
		else if (this->_R.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_R.getPosition());
		}
		else if (this->_S.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_S.getPosition());
		}
		else if (this->_T.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_T.getPosition());
		}
		else if (this->_U.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_U.getPosition());
		}
		else if (this->_V.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_V.getPosition());
		}
		else if (this->_W.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_W.getPosition());
		}
		else if (this->_X.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_X.getPosition());
		}
		else if (this->_Y.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_Y.getPosition());
		}
		else if (this->_Z.getGlobalBounds().contains(_mouse.getPosition())) {
			this->_hover.setPosition(_Z.getPosition());
		}
		else {
			this->_hover.setPosition(1280, 663);
		}
	}

	void LoginState::draw(float dt) {
		this->_data->window.clear();

		this->_data->window.draw(this->_backGround);
		this->_data->window.draw(this->_A);
		this->_data->window.draw(this->_B);
		this->_data->window.draw(this->_C);
		this->_data->window.draw(this->_D);
		this->_data->window.draw(this->_E);
		this->_data->window.draw(this->_F);
		this->_data->window.draw(this->_G);
		this->_data->window.draw(this->_H);
		this->_data->window.draw(this->_I);
		this->_data->window.draw(this->_J);
		this->_data->window.draw(this->_K);
		this->_data->window.draw(this->_L);
		this->_data->window.draw(this->_M);
		this->_data->window.draw(this->_N);
		this->_data->window.draw(this->_O);
		this->_data->window.draw(this->_P);
		this->_data->window.draw(this->_Q);
		this->_data->window.draw(this->_R);
		this->_data->window.draw(this->_S);
		this->_data->window.draw(this->_T);
		this->_data->window.draw(this->_U);
		this->_data->window.draw(this->_V);
		this->_data->window.draw(this->_W);
		this->_data->window.draw(this->_X);
		this->_data->window.draw(this->_Y);
		this->_data->window.draw(this->_Z);
		this->_data->window.draw(this->_confirm);
		this->_data->window.draw(this->_del);

		this->_data->window.draw(this->_hover);

		this->_data->window.draw(this->_name);
		this->_data->window.draw(this->_request);

		this->_data->window.draw(_mouse);

		this->_data->window.draw(this->_gate);

		this->_data->window.display();

		if (this->_gate.getTextureRect().left == 0) {
			Sleep(500);
			this->_data->machine.addState(StateRef(new DigimonSelectionState(_data)), true);
		}
	}
}