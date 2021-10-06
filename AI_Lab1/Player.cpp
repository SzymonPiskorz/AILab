#include "Player.h"

Player::Player()
{
	speed = 1.0f;
	movement = sf::Vector2f(speed, 0.0f);
	SetUpSprite();
}

void Player::ProcessEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (speed < 10)
		{
			speed++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (speed > -10)
		{
			speed--;
		}
	}

	movement = sf::Vector2f(speed, 0.0f);
}


void Player::SetUpSprite()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\pacman.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading player texture" << std::endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(300.0f, 180.0f);
}

void Player::Update()
{
	playerSprite.move(movement);
	if (playerSprite.getPosition().x > 811.0f)
	{
		playerSprite.setPosition(sf::Vector2f(-20.0f, playerSprite.getPosition().y));
	}

	if (playerSprite.getPosition().x < -21.0f)
	{
		playerSprite.setPosition(sf::Vector2f(810.0f, playerSprite.getPosition().y));
	}
}

void Player::Render(sf::RenderWindow& t_window)
{
	t_window.draw(playerSprite);
}
