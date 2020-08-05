#include "Game.hpp"
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"
#include <wtypes.h>

sf::Sprite _mouse;

namespace Med {

	void GetDesktopResolution(int& horizontal, int& vertical)
	{
		RECT desktop;
		// Get a handle to the desktop window
		const HWND hDesktop = GetDesktopWindow();
		// Get the size of screen to the variable desktop
		GetWindowRect(hDesktop, &desktop);
		// The top left corner will have coordinates (0,0)
		// and the bottom right corner will have coordinates
		// (horizontal, vertical)
		horizontal = desktop.right;
		vertical = desktop.bottom;
	}

	Game::Game(int width, int height, std::string title) {
		int h;
		int v;
		//GetDesktopResolution(h, v);

		_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
		_data->window.setMouseCursorVisible(false);
		_data->window.setFramerateLimit(60);
		_data->machine.addState(StateRef(new SplashState(this->_data)));
		_data->assets.loadTexture("Mouse Cursor", MOUSE_CURSOR_PATH);
		_mouse.setTexture(_data->assets.getTexture("Mouse Cursor"));
		this->run();
	}


	void Game::run() {
		float newTime, frameTime, interpolation;

		float curretTime = this->_clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (this->_data->window.isOpen()) {
			this->_data->machine.processStateChanges();

			newTime = this->_clock.getElapsedTime().asSeconds();
			frameTime = newTime - curretTime;

			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}

			curretTime = newTime;
			accumulator += frameTime;

			while (accumulator >= dt) {
				this->_data->machine.getActiveState()->handleInput();
				this->_data->machine.getActiveState()->update(dt);

				_mouse.setPosition(sf::Mouse::getPosition(this->_data->window).x - 1, sf::Mouse::getPosition(this->_data->window).y - 1);

				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->_data->machine.getActiveState()->draw(interpolation);
		}
	}
}