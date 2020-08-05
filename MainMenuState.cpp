#include "MainMenuState.hpp"
#include "LoginState.hpp"
#include "DEFINITIONS.hpp"

#include <sstream>
#include <iostream>

namespace Med {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {}

	void MainMenuState::init() {

		this->_data->assets.loadTexture("Main Menu Background", MAIN_MENU_SCENE8_BACKGROUND_FILEPATH);
		this->_data->assets.loadTexture("New Game Button", MAIN_MENU_NEW_GAME_BUTTON_PATH);
		this->_data->assets.loadTexture("Load Game Button", MAIN_MENU_LOAD_GAME_BUTTON_PATH);
		this->_data->assets.loadTexture("Title", MAIN_MENU_TITLE_PATH);

		this->_data->assets.loadSoundBuffer("Click", CLICK_AFX);
		this->_click.setBuffer(this->_data->assets.getSoundBuffer("Click"));

		this->_backGround.setTexture(this->_data->assets.getTexture("Main Menu Background"));
		this->_newGameButton.setTexture(this->_data->assets.getTexture("New Game Button"));
		this->_loadGameButton.setTexture(this->_data->assets.getTexture("Load Game Button"));
		this->_title.setTexture(this->_data->assets.getTexture("Title"));

		this->_title.setPosition(140, 60);
		this->_newGameButton.setPosition(80, 296);
		this->_loadGameButton.setPosition(80, 392);

		this->_data->assets._bgm.openFromFile(MAIN_MENU_BGM);
		this->_data->assets._bgm.setLoop(true);
		this->_data->assets._bgm.play();
	}

	void MainMenuState::handleInput() {
		sf::Event e;
		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
			if (this->_data->input.isSpriteClicked(this->_newGameButton, sf::Mouse::Left, this->_data->window, e)) {
				_click.play();
				this->_data->machine.addState(StateRef(new LoginState(_data)), true);
			}
			if (this->_data->input.isSpriteClicked(this->_loadGameButton, sf::Mouse::Left, this->_data->window, e)) {
				_click.play();
				std::cout << "go to load game screen" << std::endl;
			}
		}
	}

	void MainMenuState::update(float dt) {
	}

	void MainMenuState::draw(float dt) {
		this->_data->window.clear();

		this->_data->window.draw(this->_backGround);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_newGameButton);
		this->_data->window.draw(this->_loadGameButton);
		this->_data->window.draw(_mouse);

		this->_data->window.display();
	}
}