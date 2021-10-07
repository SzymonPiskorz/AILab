#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class NPC
{
	sf::Texture NPCTexture;
	sf::Sprite NPCSprite;

	sf::Vector2f movement;
	float speed;

	void SetUpSprite();

public:

	NPC();
	void Update(sf::Time t_deltaTime);
	void Render(sf::RenderWindow& t_window);
};

