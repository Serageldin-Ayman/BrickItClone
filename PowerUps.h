#pragma once
#include <sfml/Graphics.hpp>
#include "Collider.h"
#include <iostream>
#include"FallenObject.h"

class PowerUps 
{
public:
	sf::Sprite bodySprite;
	sf::Texture bodyTexture;
	sf::FloatRect bodyBounds;
	sf::RectangleShape body;
	float fallingSpeed;

public:
	PowerUps();
	void drawObject(sf::RenderWindow &window);
	void fall(float fallingSpeed);
	void destroyObject();
	void setPosition(sf::Vector2f position) { bodySprite.setPosition(position); }
	sf::FloatRect getSize() { return bodySprite.getGlobalBounds(); }
	//Collider getCollider(){ return Collider(body); }
};

