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
	NPCSprite.setOrigin(40.0f, 41.0f);
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

	if (NPCSprite.getPosition().y > WINDOW_HEIGHT +11.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(NPCSprite.getPosition().x, -10.0f));
	}

	if (NPCSprite.getPosition().y <-11.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(NPCSprite.getPosition().x , WINDOW_HEIGHT +10.0f));
	}

	if (NPCSprite.getPosition().x > WINDOW_WIDTH +11.0f)
	{
		NPCSprite.setPosition(sf::Vector2f( -10.0f, NPCSprite.getPosition().y));
	}

	if (NPCSprite.getPosition().x < -11.0f)
	{
		NPCSprite.setPosition(sf::Vector2f(WINDOW_WIDTH +10.0f, NPCSprite.getPosition().y));
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
		sf::Vector2f velocity = t_targetPos - NPCSprite.getPosition();

		if (velocity.x != 0 || velocity.y != 0)
		{
			velocity = velocity / (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y))); //normalize
			NPCSprite.setRotation(atan2f(velocity.y, velocity.x) * (180.0f / 3.14f));
			velocity *= maxSpeed;

			movement = velocity;
		}
}

void NPC::kinematicArrive(sf::Vector2f t_targetPos)
{
	sf::Vector2f velocity = t_targetPos - NPCSprite.getPosition();
	float lenght = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	if (lenght < slowDownRadius)
	{
		velocity /= timeToTarget;
		if (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y)) > minSpeed)
		{
			velocity = velocity / (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y))); //normalize
			NPCSprite.setRotation(atan2f(velocity.y, velocity.x) * (180.0f / 3.14f));
			velocity *= minSpeed;

			movement = velocity;
		}
	}
	else
	{
		velocity /= timeToTarget;
		if (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y)) > maxSpeed)
		{
			velocity = velocity / (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y))); //normalize
			NPCSprite.setRotation(atan2f(velocity.y, velocity.x) * (180.0f / 3.14f));
			velocity *= maxSpeed;

			movement = velocity;
		}

	}
}
