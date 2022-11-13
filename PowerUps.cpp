#include "PowerUps.h"
#include<time.h>
void PowerUps::drawObject(sf::RenderWindow & window)
{
	window.draw(bodySprite);
}

PowerUps::PowerUps()
{
	srand(time(0));
	float xRand = 1 + (rand() % 10);
	bodyTexture.loadFromFile("coin.png");
	bodySprite.setTexture(bodyTexture);
	bodySprite.setScale(0.03f, 0.03f);
	bodySprite.setPosition(300 + xRand, 0);
}
void PowerUps::fall(float fallingSpeed)
{
	bodySprite.move(0, fallingSpeed);
}

void PowerUps::destroyObject()
{
	fall(0);
	bodySprite.setPosition(sf::Vector2f(200.f, -20.f));
}
