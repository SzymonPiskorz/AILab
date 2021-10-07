#include "NPC.h"


NPC::NPC(int t_type)
{
	switch (t_type)
	{
	case 1:
		wander = true;
	case 2:
		seek = true;
	case 3:
		flee = true;
	default:
		break;
	}
	speed = 4.0f;
	movement = sf::Vector2f(0.0f, 0.0f);
	SetUpSprite();

	if (wander)
		kinematicWander();
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
	if(wander)
		if (timer.getElapsedTime().asSeconds() > 2)
		{
			kinematicWander();
			timer.restart();
		}

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

void NPC::kinematicWander()
{
	float rotationChange = rand() % 40 - 20;
	float rotation = NPCSprite.getRotation() + rotationChange;

	direction.x = cosf(rotation * (3.14f / 180.0f));
	direction.y = sinf(rotation * (3.14f / 180.0f));
	movement = sf::Vector2f((direction.x * speed), (direction.y * speed));
	NPCSprite.setRotation(rotation);
}

void NPC::kinematicSeek(sf::Vector2f t_targetPos)
{
	if (t_targetPos != NPCSprite.getPosition())
	{
		sf::Vector2f velocity = t_targetPos - NPCSprite.getPosition();
		velocity = velocity / (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y))); //normalize
		velocity *= maxSpeed;

		movement = velocity;
	}
}

void NPC::kinematicArrive()
{
}
