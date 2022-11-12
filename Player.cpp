#include "Player.h"


sf::FloatRect Player::GetPlayerSize()
{
	//return body.getGlobalBounds();
	return playerSprite.getGlobalBounds();
}

Player::Player(/*sf::Texture & playerTexture,*/ sf::Vector2f position)
{
	playerTexture.loadFromFile("prisoner.png");
	//body.setTexture(&playerTexture);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(position);
	playerSprite.setScale(0.3f, 0.3f);
	//playerSprite.setSize(size);
}

void Player::Update(float deltaTime, sf::View& cameraView)
{
	sf::Vector2f movement(0.f, 0.f);
	speed = 200;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= speed * deltaTime;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += speed * deltaTime;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += speed * deltaTime;
	}*/
	//body.move(movement);
	playerSprite.move(movement);
	cameraView.move(movement);
}

int Player::RewardOrPunish()
{
	return 0;
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
}
