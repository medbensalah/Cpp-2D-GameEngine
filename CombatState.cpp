#include <sstream>
#include <Windows.h>
#include <iostream>
#include "CombatState.hpp"

extern Med::Coordinator coordinator;


namespace Med {
	CombatState::CombatState(GameDataRef data) : _data(data) {}

	void CombatState::init() {
		//Components

		//systems

		//entity
		
		//entities add component
		
		//System init
		
		/*
		this->_data->assets._bgm.stop();

		this->_data->assets._bgm.openFromFile(LOGIN_BGM);
		this->_data->assets._bgm.setLoop(true);
		this->_data->assets._bgm.play();
		*/
	}

	void CombatState::handleInput() {
		sf::Event e;

		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
		}
	}

	void CombatState::update(float dt) {

	}

	void CombatState::draw(float dt) {
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.display();
	}
}