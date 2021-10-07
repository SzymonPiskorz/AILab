#include "NPC.h"


NPC::NPC()
{
	speed = 4.0f;
	movement = sf::Vector2f(1.0f, speed);
	SetUpSprite();
}

void NPC::SetUpSprite()
{
	if (!NPCTexture.loadFromFile("ASSETS\\IMAGES\\ship2.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading player texture" << std::endl;
	}
	NPCSprite.setTexture(NPCTexture);
	NPCSprite.setPosition(300.0f, 180.0f);
}

void NPC::Update(sf::Time t_deltaTime)
{
	NPCSprite.move(movement);

	if (NPCSprite.getPosition().y > 611.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(NPCSprite.getPosition().x, -20.0f));
	}

	if (NPCSprite.getPosition().y < -21.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(NPCSprite.getPosition().x , 610.0f));
	}

	if (NPCSprite.getPosition().x > 811.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(-20.0f, NPCSprite.getPosition().y));
	}

	if (NPCSprite.getPosition().x < -21.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(810.0f, NPCSprite.getPosition().y));
	}
}

void NPC::Render(sf::RenderWindow& t_window)
{
	t_window.draw(NPCSprite);
}
