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
	void Update();
	void Render(sf::RenderWindow& t_window);
};

