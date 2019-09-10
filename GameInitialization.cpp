#include "stdafx.h"
#include "GameInitialization.h"

// Initialization functions
void GameInitialization::initVariables()
{
	this->window = NULL;
	this->dt = 0.f;
}

void GameInitialization::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game");
	this->window->setFramerateLimit(120);
}

// Constructors and Destructors
GameInitialization::GameInitialization()
{
	this->initVariables();
	this->initWindow();
}

GameInitialization::~GameInitialization()
{
	delete this->window;
}

// Functions
void GameInitialization::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void GameInitialization::updateEvent()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->endApplications();
	}
}

void GameInitialization::update()
{
	this->updateEvent();
}

void GameInitialization::render()
{
	this->window->clear();
	this->window->display();
}

void GameInitialization::runApplications()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

void GameInitialization::endApplications()
{
	this->window->close();
	std::cout << "End of applications" << "\n";
}
