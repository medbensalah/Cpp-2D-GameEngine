#include "PlayerSystem.hpp"
#include <math.h>

extern Med::Coordinator coordinator;

void Med::PlayerSystem::init(Entity& entity) {
		pc = &coordinator.GetComponent<PlayerComponent>(entity);
		tc = &coordinator.GetComponent<TransformComponent>(entity);
		player.init(0, 0, 6, pc->sizeX, pc->sizeY, pc->scaleX, pc->scaleY, 6, false, pc->tex);
		idle.init(0, 0, 3, pc->sizeX, pc->sizeY, pc->scaleX, pc->scaleY, 10, true, pc->tex);
		player.setOrigin(pc->sizeX / 2, pc->sizeY * 2 / 3);
		idle.setOrigin(pc->sizeX / 2, pc->sizeY * 2 / 3);
		player.setPosition(tc->position.x, tc->position.y);
		idle.setPosition(tc->position.x, tc->position.y);
		anim = &idle;
		shadow.setRadius((pc->sizeX + 2) * pc->scaleX / 1.5f);
		shadow.setScale(1.0f, 0.5f);
		shadow.setOrigin(shadow.getRadius() / 2, shadow.getRadius() / 4);
		shadow.setPosition(tc->position.x - (shadow.getRadius() - pc->scaleX) / 2, tc->position.y + pc->sizeY * pc->scaleY / 3 - pc->scaleY * 3);
		shadow.setFillColor(sf::Color(1, 2, 48, 200));
}

void Med::PlayerSystem::handleInput(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		anim = &player;
	
		switch (event.key.code) {
		case sf::Keyboard::Z:
			if (abs(tc->velocity.x) > 1.94f) {
				tc->velocity.y = -sqrt(5) / 2.0f;
			}
			else 
				tc->velocity.y = -sqrt(5);
			idle.setXIndex(0);
			break;
		case sf::Keyboard::S:
			if (abs(tc->velocity.x) > 1.94f) {
				tc->velocity.y = sqrt(5) / 2.0f;
			}
			else
				tc->velocity.y = sqrt(5);
			idle.setXIndex(0);
			break;
		case sf::Keyboard::Q:
			if (abs(tc->velocity.y) > 1.2f) {
				tc->velocity.y /= 2.0f;
				tc->velocity.x = -sqrt(5) * sqrt(3.0f / 4.0f);
			}
			else
				tc->velocity.x = -sqrt(5);
			idle.setXIndex(0);
			break;
		case sf::Keyboard::D:
			if (abs(tc->velocity.y) > 1.2f) {
				tc->velocity.y /= 2.0f;				
				tc->velocity.x = sqrt(5) * sqrt(3.0f / 4.0f);
			}
			else
				tc->velocity.x = sqrt(5);
			idle.setXIndex(0);
			break;
		default:
			break;
		}
	}
	else if (event.type == sf::Event::KeyReleased) {
		switch (event.key.code) {
		case sf::Keyboard::Z:
			tc->velocity.y = 0;
			break;
		case sf::Keyboard::S:
			tc->velocity.y = 0;
			break;
		case sf::Keyboard::Q:
			tc->velocity.x = 0;
			if (tc->velocity.y) {
				tc->velocity.y = (tc->velocity.y / abs(tc->velocity.y)) * sqrt(5);
			}
			break;
		case sf::Keyboard::D:
			tc->velocity.x = 0;
			if (tc->velocity.y) {
				tc->velocity.y = (tc->velocity.y / abs(tc->velocity.y)) * sqrt(5);
			}
			break;
		default:
			break;
		}
	}
}

void Med::PlayerSystem::update(float dt) {
	tc->velocity += tc->acceleration;
	tc->position += tc->velocity;
	player.setPosition(tc->position.x, tc->position.y);
	idle.setPosition(tc->position.x, tc->position.y);
	shadow.setPosition(tc->position.x - (shadow.getRadius() - pc->scaleX) / 2, tc->position.y + pc->sizeY * pc->scaleY / 3 - pc->scaleY * 3);

	if (tc->velocity.x < 0) {
		pc->steps += 0.5f;
		if (tc->velocity.y < 0) {
			dd = UL;
			ds = X;
			player.setYIndex(3, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(false);
			clk.restart();
		}
		else if (tc->velocity.y > 0) {
			dd = BL;
			ds = X;
			player.setYIndex(7, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(false);
			clk.restart();
		}
		else {
			ds = L;
			player.setYIndex(5, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(false);
		}
	}
	else if (tc->velocity.x > 0) {
		pc->steps += 0.5f;

		if (tc->velocity.y < 0) {
			dd = UR;
			ds = X;
			player.setYIndex(3, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(true);
			clk.restart();
		}
		else if (tc->velocity.y > 0) {
			dd = BR;
			ds = X;
			player.setYIndex(7, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(true);
			clk.restart();
		}
		else {
			ds = R;
			player.setYIndex(5, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(true);
		}
	}
	else {
		if (tc->velocity.y < 0) {
			ds = U;
			pc->steps += 0.5f;

			player.setYIndex(1, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(false);
		}
		else if (tc->velocity.y > 0) {
			ds = B;
			pc->steps += 0.5f;

			player.setYIndex(9, pc->sizeY);
			player.setLoopLast(false);
			player.setMirror(false);
		}
		else {
			if (clk.getElapsedTime().asMilliseconds() < 330) {
				ds = X;
				switch (dd)
				{
				case Med::S:
					idle.setYIndex(8, pc->sizeY);
					idle.setMirror(false);
					break;
				case Med::UR:
					idle.setYIndex(2, pc->sizeY);
					idle.setMirror(true);
					break;
				case Med::BR:
					idle.setYIndex(6, pc->sizeY);
					idle.setMirror(true);
					break;
				case Med::BL:
					idle.setYIndex(6, pc->sizeY);
					idle.setMirror(false);
					break;
				case Med::UL:
					idle.setYIndex(2, pc->sizeY);
					idle.setMirror(false);
					break;
				default:
					break;
				}
			}
			else {
				switch (ds)
				{
				case Med::S:
					idle.setYIndex(8, pc->sizeY);
					idle.setMirror(false);
					break;
				case Med::U:
					idle.setYIndex(0, pc->sizeY);
					idle.setMirror(false);
					break;
				case Med::R:
					idle.setYIndex(4, pc->sizeY);
					idle.setMirror(true);
					break;
				case Med::B:
					idle.setYIndex(8, pc->sizeY);
					idle.setMirror(false);
					break;
				case Med::L:
					idle.setYIndex(4, pc->sizeY);
					idle.setMirror(false);
					break;
				default:
					break;
				}
			}
			idle.update(dt);
			anim = &idle;
		}
	}
	player.update(dt);
}

void Med::PlayerSystem::draw(sf::RenderWindow& window) {
	window.draw(shadow);
	window.draw(anim->getSprite());

}
