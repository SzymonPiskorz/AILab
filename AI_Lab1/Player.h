#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height /4 * 3
#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width /4 * 3

class Player
{
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Vector2f movement;
	float speed;
	float acceleration;
	float rotationSpeed;
	float minSpeed;
	float maxSpeed;

	sf::Vector2f direction;

	void SetUpSprite();

public:

	Player();
	void ProcessEvents();
	void Update(sf::Time t_deltaTime);
	void Render(sf::RenderWindow& t_window);
	sf::Vector2f getPosition();
};

