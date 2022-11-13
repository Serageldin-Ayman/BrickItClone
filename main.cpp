#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include"Collider.h"
#include"Animation.h"
#include"Rocks.h"
#include"PowerUps.h"

#define WINDOW_WIDTH 907
#define WINDOW_HEIGHT 900

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Testing Mechanics");
	sf::View view(sf::FloatRect(WINDOW_WIDTH/2, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

	Player player(sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT-290));

	window.setFramerateLimit(60);
	//redBox.setPosition(sf::Vector2f(0.f, 500.f));
	//view.setSize(1000.f, 860.f);
	sf::Texture background;
	sf::Sprite backgroundSprite;
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize = sf::Vector2u(WINDOW_WIDTH*2, 900);

	background.loadFromFile("backgroundDaiFinal.jpg");
	TextureSize = background.getSize();

	float scaleX = (float)WindowSize.x / TextureSize.x;
	float scaleY = (float)WindowSize.y / TextureSize.y;


	backgroundSprite.setTexture(background);
	backgroundSprite.setScale(scaleX, scaleY);

	//backgroundSprite.setScale(0.5f, 0.5f);
	//view.setCenter(400.f, 300.f);

	Rocks rockArr[20];
	PowerUps coinArr[20];

	for (int i = 0; i < 20; i++)
	{
		rockArr[i].setPosition(sf::Vector2f(100+(i*100),0));
		coinArr[i].setPosition(sf::Vector2f(100 + (i * 80), 0));
	}

	Rocks rock;
	PowerUps coin;

	//FallenObject Objects[20];
	//int j = 0;
	/*for (int i = 0, y_pos = 10; i < 20; i++,y_pos+=10)
	{
		Objects[i].bodyTexture.loadFromFile("rock.png");
		//bodyTexture.loadFromFile("rock.png");
		Objects[i].bodySprite.setTexture(bodyTexture);
		bodySprite.setTexture(bodyTexture);
		bodySprite.setScale(0.1f, 0.1f);
		//Objects[i].bodySprite.setPosition(sf::Vector2f(500.f,y_pos+10));
	}*/
	sf::Clock clock;

	float deltaTime = 0;
	float time = 0;
	while (window.isOpen())
	{
		float currentTime = clock.getElapsedTime().asSeconds();
		deltaTime = currentTime - time;
		time = currentTime;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		for (int i = 0; i < 20; i++)
		{
			rockArr[i].fall(2);
			coinArr[i].fall(1.5);
		}
		player.Update(deltaTime, view, rockArr, coinArr, 5);
		player.screenCollision();
		
		
		window.clear();
		window.draw(backgroundSprite);
		player.Draw(window);

		for (int i = 0; i < 5; i++)
		{
			rockArr[i].drawObject(window);
			coinArr[i].drawObject(window);
		}
		
		
		window.setView(view);
		window.display();
	}

	return 0;
}