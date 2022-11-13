#include <iostream>
#include "Player.h"
#include"Rocks.h"
#include"PowerUps.h"

using namespace std;

#define WINDOW_WIDTH  907
#define WINDOW_HEIGHT  900

sf::FloatRect Player::GetPlayerSize()
{
	//return body.getGlobalBounds();
	return playerSprite.getGlobalBounds();
}

Player::Player(/*sf::Texture & playerTexture,*/ sf::Vector2f position)
{
	if (!playerTexture.loadFromFile("dai.png"))
	{
		throw "Player image is not loaded";
	}
	playerSprite.setScale(0.3f, 0.3f);
	//body.setTexture(&playerTexture);
	playerSprite.setTexture(playerTexture);
	playerSprite.setPosition(position);
	//body.setPosition(position);
	playerSprite.setScale(0.08f, 0.08f);
	playerScore = 0;
	playerHealth = 5;
	
	//playerSprite.setSize(size);
}

void Player::Update (float deltaTime, sf::View& cameraView, Rocks* rock, PowerUps* coin, int arrSize)
{
	sf::Vector2f movement(0.f, 0.f);
	speed = 400;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		//cout << cameraView.getCenter().x << endl;
		playerSprite.setScale(0.08f, 0.08f);
		playerSprite.setOrigin(0, 0);
		movement.x -= speed * deltaTime;
		if (cameraView.getCenter().x > 454)
		{
			cameraView.move(movement);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		playerSprite.setScale(-0.08f, 0.08f);
		playerSprite.setOrigin(playerSprite.getLocalBounds().width, 0);
		movement.x += speed * deltaTime;
		if (cameraView.getCenter().x < 1360)
		{
			cameraView.move(movement);
		}
	}
	//body.move(movement);
	playerSprite.move(movement);
	for (int i = 0; i < arrSize; i++)
	{
		if (playerSprite.getGlobalBounds().intersects(rock[i].getSize()) == true)
		{
			playerHealth--;
			rock[i].destroyObject();
			std::cout << "Collided with a rock" << std::endl;
		}
		else if (playerSprite.getGlobalBounds().intersects(coin[i].getSize()) == true)
		{
			playerScore++;
			coin[i].destroyObject();
			std::cout << "Collided with a coin" << std::endl;
		}
	}
	
	//cameraView.move(movement);
}
void Player::Draw(sf::RenderWindow& window)
{
	//window.draw(body);
	window.draw(playerSprite);
}

void Player::screenCollision()
{
	//cout << playerSprite.getPosition().x << ", " << playerSprite.getPosition().y << endl;
	// left collision
	if (playerSprite.getPosition().x <= 0)
	{
		playerSprite.setPosition(0, playerSprite.getPosition().y);
	}

	// right collision
	if (playerSprite.getPosition().x > WINDOW_WIDTH * 2 - playerSprite.getGlobalBounds().width)
	{
		playerSprite.setPosition(WINDOW_WIDTH * 2 - playerSprite.getGlobalBounds().width, playerSprite.getPosition().y);
	}
}


/********************************************************************************************/

/*#include "Player.h"


//sf::FloatRect Player::GetPlayerSize()
//{
//	playerBounds = body.getGlobalBounds();
//	return playerBounds;
//}

Player::Player(sf::Vector2f position)
{
	//playerTexture.loadFromFile("prisoner.png");
	//body.setTexture(&playerTexture);
	//body.setTexture(playerTexture);
	body.setPosition(position);
	body.setFillColor(sf::Color::Green);
	//body.setScale(0.3f, 0.3f);
	//playerSprite.setPosition(position);
	//playerSprite.setScale(0.3f, 0.3f);
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
	}
	body.move(movement);
	//playerSprite.move(movement);
	//playerBounds.left = playerSprite.getPosition().x;
	std::cout << "Player is at " << body.getPosition().x << " And " << body.getPosition().y << std::endl;
	//cameraView.move(movement);
}

//int Player::RewardOrPunish()
//{
//
//	return 0;
//}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}*/