#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define WINDOW_HEIGHT sf::VideoMode::getDesktopMode().height /4 * 3
#define WINDOW_WIDTH sf::VideoMode::getDesktopMode().width /4 * 3

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

	float timeToTarget = 0.5f;
	float slowDownRadius = 400.0f;
	float stopRadius = 200.0f;
	
public:

	NPC(int);
	void Update(sf::Time t_deltaTime);
	void Render(sf::RenderWindow& t_window);
	void kinematicWander();
	void kinematicSeek(sf::Vector2f);
	void kinematicArrive(sf::Vector2f);
};

