#pragma once
#include"SFML/Graphics.hpp"
#include"Rocks.h"
#include"PowerUps.h"
class Player : public sf::Sprite
{
	//Attributes
private:
	float speed;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	unsigned int playerScore;
	unsigned int playerHealth;
	sf::FloatRect playerBounds;
	//sf::RectangleShape body;
	int flag;
	//sf::View cameraView;
	//FallenObject rock;

public:
	Player(sf::Vector2f position);
	//void setTexture(sf::Texture& playerTexture);
	void Update(float deltaTime, sf::View& cameraView, Rocks* rock, PowerUps* coin, int arrSize);
	//void Update(float deltaTime, sf::View& cameraView, FallenObject& coin);
	//int RewardOrPunish();
	void Draw(sf::RenderWindow& window);
	void screenCollision();
private:
	sf::FloatRect GetPlayerSize();

};
