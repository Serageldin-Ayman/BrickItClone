#include "Rocks.h"

void Rocks::drawObject(sf::RenderWindow & window)
{
	window.draw(bodySprite);
}

Rocks::Rocks()
{
	bodyTexture.loadFromFile("rock.png");
	bodySprite.setTexture(bodyTexture);
	bodySprite.setScale(0.1f, 0.1f);
	bodySprite.setPosition(300.f, 0);
}
void Rocks::fall(float fallingSpeed)
{
	bodySprite.move(0, fallingSpeed);
}

void Rocks::destroyObject()
{
	fall(0);
	bodySprite.setPosition(sf::Vector2f(200.f, -20.f));
}
