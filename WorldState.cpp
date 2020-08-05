#include <sstream>
#include <Windows.h>
#include <iostream>
#include "WorldState.hpp"

Med::Coordinator coordinator;


namespace Med {
	WorldState::WorldState(GameDataRef data) : _data(data) {}

	void WorldState::init() {

		_data->assets.clearTex();

		coordinator.Init();

		//Components
		coordinator.RegisterComponent<TransformComponent>();
		coordinator.RegisterComponent<PlayerComponent>();
		coordinator.RegisterComponent<ColliderComponent>();


		//systems
		playerSystem = coordinator.RegisterSystem<PlayerSystem>();
		Signature sig;
		sig.set(coordinator.GetComponentType<PlayerComponent>());
		sig.set(coordinator.GetComponentType<TransformComponent>());
		sig.set(coordinator.GetComponentType<ColliderComponent>());
		coordinator.SetSystemSignature<PlayerSystem>(sig);

		collisionSystem = coordinator.RegisterSystem<CollisionSystem>();
		sig.reset();
		sig.set(coordinator.GetComponentType<ColliderComponent>());
		coordinator.SetSystemSignature<CollisionSystem>(sig);


		//entity
		player = coordinator.CreateEntity();

		//entities add component
		_data->assets.loadTexture("player", PLAYER_TILESET);
		coordinator.AddComponent(player, PlayerComponent{
											 20,
											 32,
											 2.5,
											 5,
											 playerName,
											 playerDigimon,
											 _data->assets.getTexture("player"),
											 0.0f
		});
		coordinator.AddComponent(player, TransformComponent{
											 Vec2D(20, 20),
											 Vec2D(0, 0),
											 Vec2D(0, 0)
		});

		//System init
		playerSystem->init(player);
		collisionSystem->init(player);


		camera.setCenter(coordinator.GetComponent<TransformComponent>(player).position.x,
			coordinator.GetComponent<TransformComponent>(player).position.y);
		camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

		_data->assets.loadTexture("maptex", "Resources/res/ingame/maps/tiles.png");
		Map map1(7, 20, 64, "Resources/res/ingame/maps/new map", _data->assets.getTexture("maptex"), true);
		_data->assets.loadMap("1", map1);
		/*
		this->_data->assets._bgm.stop();

		this->_data->assets._bgm.openFromFile(LOGIN_BGM);
		this->_data->assets._bgm.setLoop(true);
		this->_data->assets._bgm.play();
		*/
	}

	void WorldState::handleInput() {
		sf::Event e;

		while (this->_data->window.pollEvent(e)) {
			if (sf::Event::Closed == e.type) {
				this->_data->window.close();
			}
			playerSystem->handleInput(e);
		}
	}

	void WorldState::update(float dt) {

		playerSystem->update(dt);
		collisionSystem->update(dt);
		
		camera.setCenter(coordinator.GetComponent<TransformComponent>(player).position.x,
			coordinator.GetComponent<TransformComponent>(player).position.y);
		_data->window.setView(camera);
	}

	void WorldState::draw(float dt) {
		this->_data->window.clear(sf::Color::Black);

		_data->assets.getMap("1").draw(_data->window);
		playerSystem->draw(_data->window);
	//	collisionSystem->draw(_data->window);

		this->_data->window.display();
	}
}