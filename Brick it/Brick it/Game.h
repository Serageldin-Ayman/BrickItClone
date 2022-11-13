#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Brickit
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Texture obs;
	sf::Texture goldz;


	//Game logic
	bool endGame;
	unsigned points;
	int health;
	//int score;---------------------------------------score

	//Obstacles vars
	float ObstaclesSpawnTimer;
	float ObstaclesSpawnTimerMax;
	int maxnumOfObstacles;
	//Gold vars
	float GoldSpawnTimer;
	float GoldSpawnTimerMax;
	int maxnumOfGold;


	//Game Obstacles  
	std::vector<sf::RectangleShape> Obstacles;
	sf::RectangleShape Obstacle;
	
	std::vector<sf::CircleShape> Golds;
	sf::CircleShape Gold;
 

	//Private functions
	void initVariables();
	void initWindow();
	void initObstacles();
	void initGold();//------------------------------------------------new
	void initObs();
	void initgoldz();




public:
	//Constructors / Destructors
	Brickit();
	virtual ~Brickit();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;

	//Functions  
	void spawnObstacles();
	void spwanGold();//------------------------------------------------new

	void pollEvents();
	void updateObstaclesspawnTimer();
	void updateGoldspawnTimer();//----------------------------------------new
	void update();

 
	void renderObstacles(sf::RenderTarget& target);
	void renderGold(sf::RenderTarget& target); 
	void renderobs(sf::RenderTarget& target);
	void rendergoldz(sf::RenderTarget& target);
	void render();

};
