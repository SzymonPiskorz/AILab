#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Vector2f movement;
	float speed;

	void SetUpSprite();

public:

	Player();
	void ProcessEvents();
	void Update();
	void Render(sf::RenderWindow& t_window);
};

