#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class NPC
{
	sf::Texture NPCTexture;
	sf::Sprite NPCSprite;

	sf::Vector2f movement;
	float speed;
	float rotationSpeed;
	sf::Vector2f direction;
	sf::Clock timer;
	void SetUpSprite();
	bool wander = false;
	bool seek = false;
	bool flee = false;

	float minSpeed = 1;
	float maxSpeed = 4;
	
public:

	NPC(int);
	void Update(sf::Time t_deltaTime);
	void Render(sf::RenderWindow& t_window);
	void kinematicWander();
	void kinematicSeek(sf::Vector2f);
	void kinematicArrive();
};

