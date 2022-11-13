#include <iostream>
#include "Game.h"
#include <iostream>

//Private functions
void Brickit::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->endGame = false;
	this->points = 0;
	this->health = 20;
	this->ObstaclesSpawnTimerMax = 20.f;
	this->ObstaclesSpawnTimer = this->ObstaclesSpawnTimerMax;
	this->maxnumOfObstacles = 5;

	this->GoldSpawnTimerMax = 20.f;
	this->GoldSpawnTimer = this->GoldSpawnTimerMax;
	this->maxnumOfGold = 5;
}

void Brickit::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	//Dynamiclly allocate the window
	this->window = new sf::RenderWindow(this->videoMode, "Brickit", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}


void Brickit::initObstacles()
{
	this->Obstacle.setPosition(10.f, 10.f);
	this->Obstacle.setSize(sf::Vector2f(100.f, 100.f));
	this->Obstacle.setFillColor(sf::Color::Red);
}

void Brickit::initGold()
{
	this->Gold.setPosition(10.f, 10.f);
	this->Gold.setRadius(40.f);
	this->Gold.setFillColor(sf::Color::Yellow);
}

void Brickit::initObs()
{
	this->obs.loadFromFile("Fall.png");
}

void Brickit::initgoldz()
{
	this->goldz.loadFromFile("coin.png");
}

//Constructors / Destructors
Brickit::Brickit()
{
	this->initVariables();
	this->initWindow();
	this->initObstacles();
	this->initGold();
	void initObs();
	void initgoldz();
}

Brickit::~Brickit()
{
	delete this->window;
}

//Accessors
const bool Brickit::running() const
{
	return this->window->isOpen();
}

const bool Brickit::getEndGame() const
{
	return this->endGame;
}

//Functions

void Brickit::spwanGold()
{
	int type = rand() % 5;
	this->Gold.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->Gold.getRadius())),
		0.f
	);

	// Randomize Gold 
		int type1 = rand() % 5;

	switch (type1)
	{
	case1:
		this->Gold.setRadius(25.f);
		this->Gold.setFillColor(sf::Color::Yellow);
		break;
	default:
		this->Gold.setRadius(20.f);
		this->Gold.setFillColor(sf::Color::Yellow);
		break;
	}

	//Spawn the enemy
	this->Golds.push_back(this->Gold);
}

void Brickit::spawnObstacles()
{
	/*
		When return void
		Spawns Obstacles and sets their types and colors. Spawns them at random positions.
		-Sets a random type.
		-Sets a random position.
		-Sets a random color.
		-Adds Obstacles to the vector.
	*/

	this->Obstacle.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->Obstacle.getSize().x)),
		0.f
	);

	//Randomize Obstacles type
	int type = rand() % 5;

	switch (type)
	{
	case1:
		this->Obstacle.setSize(sf::Vector2f(55.f, 55.f));
		this->Obstacle.setFillColor(sf::Color::Red);
		break;
	default:
		this->Obstacle.setSize(sf::Vector2f(60.f,60.f));
		this->Obstacle.setFillColor(sf::Color::Red);
		break;
	}

	//Spawn the enemy
	this->Obstacles.push_back(this->Obstacle);
}

void Brickit::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}


void Brickit::updateObstaclesspawnTimer()
{
	/**
		@return void
		Updates the enemy spawn timer and spawns enemies
		When the total amount of enemies is smaller than the maximum.
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen. //TODO
	*/

	//Updating the timer for enemy spawning
	if (this->Obstacles.size() < this->maxnumOfObstacles)
	{
		if (this->ObstaclesSpawnTimer >= this->ObstaclesSpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spawnObstacles();
			this->ObstaclesSpawnTimer = 0.f;
		}
		else
			this->ObstaclesSpawnTimer += 1.f;
	}

	//Moving and updating enemies
	for (int i = 0; i < this->Obstacles.size(); i++)
	{
		bool deleted = false;

		this->Obstacles[i].move(0.f, 5.f);

		if (this->Obstacles[i].getPosition().y > this->window->getSize().y)
		{
			this->Obstacles.erase(this->Obstacles.begin() + i);
			this->health -= 1;
		}
	}
}

void Brickit::updateGoldspawnTimer()
{
	/**
		@return void
		Updates the enemy spawn timer and spawns enemies
		When the total amount of enemies is smaller than the maximum.
		Moves the enemies downwards.
		Removes the enemies at the edge of the screen. //TODO
	*/

	//Updating the timer for enemy spawning
	if (this->Golds.size() < this->maxnumOfGold)
	{
		if (this->GoldSpawnTimer >= this->GoldSpawnTimerMax)
		{
			//Spawn the enemy and reset the timer
			this->spwanGold();
			this->GoldSpawnTimer = 0.f;
		}
		else
			this->GoldSpawnTimer += 3.f;
	}

	//Moving and updating gold
	for (int i = 0; i < this->Golds.size(); i++)
	{
		bool deleted = false;

		this->Golds[i].move(0.f, 8.f);

		if (this->Golds[i].getPosition().y > this->window->getSize().y)
		{
			this->Golds.erase(this->Golds.begin() + i);
			//this->health -= 1; score ?
		}
	}
}

void Brickit::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->updateObstaclesspawnTimer();
	}
	if (this->endGame == false)
	{
		this->updateGoldspawnTimer();
	}

	//End game condition
	if (this->health <= 0)
		this->endGame = true;
}


void Brickit::renderObstacles(sf::RenderTarget& target)
{
	//Rendering all the enemies
	for (auto &e : this->Obstacles)
	{
		target.draw(e);
	}
}

void Brickit::renderGold(sf::RenderTarget & target)
{
	for (auto &e : this->Golds)
	{
		target.draw(e);
	}
}
//render the texture of obs
void Brickit::renderobs(sf::RenderTarget & target)
{
	for (auto &e : this->obs)
	{
		target.draw(e);
	}
}
//render the texture of goldz
void Brickit::rendergoldz(sf::RenderTarget & target)
{
	for (auto &e : this->goldz)
	{
		target.draw(e);
	}
}


void Brickit::render()
{
	/**
		@return void
		- clear old frame
		- render objects
		- display frame in window
		Renders the game objects.
	*/

	this->window->clear();

	//Draw game objects
	this->renderObstacles(*this->window);
	this->renderGold(*this->window);
	this->window->display();
	this->renderobs(*this->window);
	this->rendergoldz(*this->window);
}

int main()
{
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	Brickit game;

	//Game loop
	while (game.running() && !game.getEndGame())
	{
		//Update
		game.update();

		//Render
		game.render();
	}

	//End of application
	return 0;
}