#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider
{
private:
	sf::RectangleShape& body;

public:
	Collider(sf::RectangleShape& body);

	bool checkObjCollision(Collider& other);

	sf::Vector2f getPosition();
	sf::Vector2f getHalfSize();
};

#endif
