#include "DigimonSelectionState.hpp"
#include "DEFINITIONS.hpp"
#include "IntroductionFMVState.hpp"

#include <Windows.h>
#include <sstream>
#include <iostream>

int playerDigimon = -1;

namespace Med {
	DigimonSelectionState::DigimonSelectionState(GameDataRef data) : _data(data) {}

	void DigimonSelectionState::init() {

		if (playerName.getString() == "")
			playerName.setString("test");

		this->_data->assets.loadTexture("Box", SELECTION_BOX);
		this->_data->assets.loadTexture("Hover Box", SELECTION_BOX_HOVER);
		this->_data->assets.loadTexture("Terriermon Idle", TERRIERMON_ANIMATION);
		this->_data->assets.loadTexture("Veemon Idle", VEEMON_ANIMATION);
		this->_data->assets.loadTexture("Impmon Idle", IMPMON_ANIMATION);
		this->_data->assets.loadTexture("Digimon Selection Background", DIGIMON_SELECTION_SCENE_BACKGROUND);
		this->_backGround.setTexture(this->_data->assets.getTexture("Digimon Selection Background"));

		this->_box1.setTexture(this->_data->assets.getTexture("Box"));
		this->_box2.setTexture(this->_data->assets.getTexture("Box"));
		this->_box3.setTexture(this->_data->assets.getTexture("Box"));
		this->_box1.setScale(3.2, 3.5);
		this->_box2.setScale(3.2, 3.5);
		this->_box3.setScale(3.2, 3.5);
		this->_hoverBox.setTexture(this->_data->assets.getTexture("Hover Box"));

		this->_terriermon = new Animation(0, 0, 10, 48, 48, 3, 6, false, this->_data->assets.getTexture("Terriermon Idle"));
		this->_terriermon->setPosition(110, 95);
		this->_veemon = new Animation(0, 0, 10, 48, 48, 3, 6, false, this->_data->assets.getTexture("Veemon Idle"));
		this->_veemon->setPosition(110, 250);
		this->_impmon = new Animation(0, 0, 8, 48, 48, 3, 6, false, this->_data->assets.getTexture("Impmon Idle"));
		this->_impmon->setPosition(105, 422);

		this->_terriermonS = new Animation(0, 1, 15, 48, 48, 3, 6, false, this->_data->assets.getTexture("Terriermon Idle"));
		this->_terriermonS->setPosition(110, 95);
		this->_veemonS = new Animation(0, 1, 7, 48, 48, 3, 6, false, this->_data->assets.getTexture("Veemon Idle"));
		this->_veemonS->setPosition(110, 250);
		this->_impmonS = new Animation(0, 1, 10, 48, 48, 3, 6, true, this->_data->assets.getTexture("Impmon Idle"));
		this->_impmonS->setPosition(105, 422);
		
		this->_gateEffects.setBuffer(this->_data->assets.getSoundBuffer("Gate"));
		this->_click.setBuffer(this->_data->assets.getSoundBuffer("Click"));
		this->_gateEffects.setPlayingOffset(sf::milliseconds(700));

		this->_data->assets.loadSoundBuffer("Typing", TYPING_SFX_FILEPATH);
		this->_typing.setBuffer(this->_data->assets.getSoundBuffer("Typing"));

		this->_gate.setTexture(this->_data->assets.getTexture("Login Gate"));
		this->_gate.setTextureRect(sf::IntRect(0, 0, 1280, 663));
		this->_confirm.setTexture(this->_data->assets.getTexture("Login Confirm Button"));



		this->_requestText.setFont(this->_data->assets.getFont("bookos"));
		this->_requestText.setCharacterSize(30);
		this->_requestText.setFillColor(sf::Color(140, 209, 251, 255));
		this->_requestText.setLetterSpacing(5);
		this->_requestText.setStyle(sf::Text::Bold);
		this->_requestText.setPosition(40, 30);

		this->_TDescriptionText.setFont(this->_data->assets.getFont("bookos"));
		this->_TDescriptionText.setCharacterSize(20);
		this->_TDescriptionText.setFillColor(sf::Color(140, 209, 251, 255));
		this->_TDescriptionText.setLetterSpacing(3);
		this->_TDescriptionText.setPosition(320, 182);

		this->_VDescriptionText.setFont(this->_data->assets.getFont("bookos"));
		this->_VDescriptionText.setCharacterSize(20);
		this->_VDescriptionText.setFillColor(sf::Color(140, 209, 251, 255));
		this->_VDescriptionText.setLetterSpacing(3);
		this->_VDescriptionText.setPosition(320, 347);

		this->_IDescriptionText.setFont(this->_data->assets.getFont("bookos"));
		this->_IDescriptionText.setCharacterSize(20);
		this->_IDescriptionText.setFillColor(sf::Color(140, 209, 251, 255));
		this->_IDescriptionText.setLetterSpacing(3);
		this->_IDescriptionText.setPosition(320, 513);



		_typing.setPlayingOffset(sf::milliseconds(100));

		_box1.setPosition(109, 108);
		_box2.setPosition(109, 273);
		_box3.setPosition(109, 439);


		this->_confirm.setPosition(1080, 540);

	}

	bool closingGate1 = false;

	void DigimonSelectionState::handleInput() {
		sf::Event e;
		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
			if (this->_data->input.isSpriteClicked(this->_box1, sf::Mouse::Left, this->_data->window, e)) {
				_click.play();
				playerDigimon = TERRIERMON;
			}
			if (this->_data->input.isSpriteClicked(this->_box2, sf::Mouse::Left, this->_data->window, e)) {
				_click.play();
				playerDigimon = VEEMON;
			}
			if (this->_data->input.isSpriteClicked(this->_box3, sf::Mouse::Left, this->_data->window, e)) {
				_click.play();
				playerDigimon = IMPMON;
			}

			if (this->_data->input.isSpriteClicked(this->_confirm, sf::Mouse::Left, this->_data->window, e)) {
				if (this->_gate.getTextureRect().left == 12800 && playerDigimon != -1) {
					_click.play();
					closingGate1 = true;
				}
			}
		}
	}
	
	sf::Clock clk1;
	int c1 = 1100;

	void DigimonSelectionState::update(float dt) {
		//digimon
		this->_terriermon->update(dt);
		this->_veemon->update(dt);
		this->_impmon->update(dt);

		//typing
		if (clk1.getElapsedTime().asSeconds() >= 2.5f) {
			if (_typeClock.getElapsedTime().asMilliseconds() >= 100 && _textChar < _request.length()) {
				_requestText.setString(_requestText.getString() + _request[_textChar]);
				if (_request[_textChar] != '\n' && _request[_textChar] != '.' && _request[_textChar] != ' ') {
					_typing.play();
					_typing.setPlayingOffset(sf::milliseconds(100));
				}
				_textChar++;
				_typeClock.restart();
			}
		}
		if (_textChar == _request.length()) {
			if (_typeClock.getElapsedTime().asMilliseconds() >= 100 && _TDChar < _TDescription.length()) {
				_TDescriptionText.setString(_TDescriptionText.getString() + _TDescription[_TDChar]);
				if (_TDescription[_TDChar] != '\n' && _TDescription[_TDChar] != '.' && _TDescription[_TDChar] != ' ') {
					_typing.play();
					_typing.setPlayingOffset(sf::milliseconds(100));
				}
				_TDChar++;
				_typeClock.restart();
			}
		}
		if (_TDChar == _TDescription.length()) {
			if (_typeClock.getElapsedTime().asMilliseconds() >= 100 && _VDChar < _VDescription.length()) {
				_VDescriptionText.setString(_VDescriptionText.getString() + _VDescription[_VDChar]);
				if (_VDescription[_VDChar] != '\n' && _VDescription[_VDChar] != '.' && _VDescription[_VDChar] != ' ') {
					_typing.play();
					_typing.setPlayingOffset(sf::milliseconds(100));
				}
				_VDChar++;
				_typeClock.restart();
			}
		}
		if (_VDChar == _VDescription.length()) {
			if (_typeClock.getElapsedTime().asMilliseconds() >= 100 && _IDChar < _IDescription.length()) {
				_IDescriptionText.setString(_IDescriptionText.getString() + _IDescription[_IDChar]);
				if (_IDescription[_IDChar] != '\n' && _IDescription[_IDChar] != '.' && _IDescription[_IDChar] != ' ') {
					_typing.play();
					_typing.setPlayingOffset(sf::milliseconds(100));
				}
				_IDChar++;
				_typeClock.restart();
			}
		}
		//gate
		if (static_cast<int>(clk1.getElapsedTime().asMilliseconds()) - c1 > 20) {
			if (this->_gate.getTextureRect().left != 12800 && !closingGate1) {
				if (this->_gate.getTextureRect().left == 0) {
					_gateEffects.play();
				}
				this->_gate.setTextureRect(sf::IntRect(this->_gate.getTextureRect().left + 1280, 0, 1280, 663));
				c1 = static_cast<int>(clk1.getElapsedTime().asMilliseconds());
			}
			else if (this->_gate.getTextureRect().left != 0 && closingGate1) {
				if (this->_gate.getTextureRect().left == 12800) {
					_gateEffects.setPlayingOffset(sf::milliseconds(500));
					_gateEffects.play();
				}
				this->_gate.setTextureRect(sf::IntRect(this->_gate.getTextureRect().left - 1280, 0, 1280, 663));
				c1 = static_cast<int>(clk1.getElapsedTime().asMilliseconds());

			}
		}
	}

	void DigimonSelectionState::draw(float dt) {
		this->_data->window.clear();

		
		this->_data->window.draw(this->_backGround);
		

		this->_data->window.draw(this->_box1);
		this->_data->window.draw(this->_box2);
		this->_data->window.draw(this->_box3);

		switch (playerDigimon)
		{
		case -1:
			this->_data->window.draw(this->_terriermon->getSprite());
			this->_data->window.draw(this->_veemon->getSprite());
			this->_data->window.draw(this->_impmon->getSprite());
			break;
		case 1:
			this->_veemonS->setXIndex(0);
			this->_impmonS->setXIndex(0);
			this->_terriermonS->update(dt);
			this->_data->window.draw(this->_terriermonS->getSprite());
			this->_data->window.draw(this->_veemon->getSprite());
			this->_data->window.draw(this->_impmon->getSprite());
			this->_box1.setTexture(this->_data->assets.getTexture("Hover Box"));
			this->_box2.setTexture(this->_data->assets.getTexture("Box"));
			this->_box3.setTexture(this->_data->assets.getTexture("Box"));
			break;
		case 2:
			this->_impmonS->setXIndex(0);
			this->_terriermonS->setXIndex(0);
			this->_veemonS->update(dt);
			this->_data->window.draw(this->_terriermon->getSprite());
			this->_data->window.draw(this->_veemonS->getSprite());
			this->_data->window.draw(this->_impmon->getSprite());
			this->_box2.setTexture(this->_data->assets.getTexture("Hover Box"));
			this->_box1.setTexture(this->_data->assets.getTexture("Box"));
			this->_box3.setTexture(this->_data->assets.getTexture("Box"));
			break;
		case 3:
			this->_veemonS->setXIndex(0);
			this->_terriermonS->setXIndex(0);
			this->_impmonS->update(dt);
			this->_data->window.draw(this->_terriermon->getSprite());
			this->_data->window.draw(this->_veemon->getSprite());
			this->_data->window.draw(this->_impmonS->getSprite());
			this->_box3.setTexture(this->_data->assets.getTexture("Hover Box"));
			this->_box1.setTexture(this->_data->assets.getTexture("Box"));
			this->_box2.setTexture(this->_data->assets.getTexture("Box"));
			break;
		default:
			break;
		}
		

		this->_data->window.draw(this->_confirm);

		this->_data->window.draw(this->_requestText);
		this->_data->window.draw(this->_TDescriptionText);
		this->_data->window.draw(this->_VDescriptionText);
		this->_data->window.draw(this->_IDescriptionText);


		this->_data->window.draw(_mouse);

		this->_data->window.draw(this->_gate);

		this->_data->window.display();

		if (this->_gate.getTextureRect().left == 0) {
			delete _terriermon;
			delete _terriermonS;
			delete _veemon;
			delete _veemonS;
			delete _impmon;
			delete _impmonS;
			this->_data->assets._bgm.stop();
			this->_data->machine.addState(StateRef(new IntroductionFMVState(_data)), true);
		}
	}
}