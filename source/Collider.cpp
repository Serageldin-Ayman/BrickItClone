#include <iostream>
#include "Collider.h"

using namespace std;

Collider::Collider(sf::RectangleShape& body) :
	body(body)
{

}

bool Collider::checkObjCollision(Collider & other)
{
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();

	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		cout << "collision\n";
		return true;
	}
	return false;
}

sf::Vector2f Collider::getPosition()
{
	return body.getPosition();
}

sf::Vector2f Collider::getHalfSize()
{
	return body.getSize() / 2.0f;
}