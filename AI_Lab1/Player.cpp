#include "Player.h"

Player::Player()
{
	speed = 0.0f;
	movement = sf::Vector2f(0.0f, 0.0f);
	acceleration = 50.0f;
	rotationSpeed = 20.0f;

	minSpeed = -5.0f;
	maxSpeed = 10.0f;

	SetUpSprite();
}

void Player::ProcessEvents()
{
	
}


void Player::SetUpSprite()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\ship1.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading player texture" << std::endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(300.0f, 180.0f);
	playerSprite.setOrigin(40.0f, 41.0f);
}

void Player::Update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed += acceleration * t_deltaTime.asSeconds();
		if (speed > maxSpeed) speed = maxSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed -= acceleration * t_deltaTime.asSeconds();
		if (speed < minSpeed) speed = minSpeed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerSprite.setRotation(playerSprite.getRotation() - speed * rotationSpeed * t_deltaTime.asSeconds());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		playerSprite.setRotation(playerSprite.getRotation() + speed * rotationSpeed * t_deltaTime.asSeconds());
	}

	direction.x = cosf(playerSprite.getRotation() * (3.14f / 180.0f));
	direction.y = sinf(playerSprite.getRotation() * (3.14f / 180.0f));
	movement = sf::Vector2f((direction.x * speed /** t_deltaTime.asSeconds()*/), (direction.y * speed /** t_deltaTime.asSeconds()*/));

	playerSprite.move(movement);

	if (playerSprite.getPosition().x > 811.0f)
	{
		playerSprite.setPosition(sf::Vector2f(-10.0f, playerSprite.getPosition().y));
	}

	if (playerSprite.getPosition().x < -11.0f)
	{
		playerSprite.setPosition(sf::Vector2f(810.0f, playerSprite.getPosition().y));
	}
	if (playerSprite.getPosition().y > 611.0f)
	{
		playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, -10.0f));
	}

	if (playerSprite.getPosition().y < -11.0f)
	{
		playerSprite.setPosition(sf::Vector2f(playerSprite.getPosition().x, 610.0f));
	}
}

void Player::Render(sf::RenderWindow& t_window)
{
	t_window.draw(playerSprite);
}

sf::Vector2f Player::getPosition()
{
	return playerSprite.getPosition();
}
