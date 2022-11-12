#pragma once
#include"SFML/Graphics.hpp"
class Player
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

public:
	Player(sf::Vector2f position);
	//void setTexture(sf::Texture& playerTexture);
	void Update(float deltaTime, sf::View& cameraView);
	int RewardOrPunish();
	void Draw(sf::RenderWindow& window);
private:
	sf::FloatRect GetPlayerSize();

};

