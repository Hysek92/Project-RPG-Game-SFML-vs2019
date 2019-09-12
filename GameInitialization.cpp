#include "stdafx.h"
#include "GameInitialization.h"

// Initialization functions
void GameInitialization::initVariables()
{
	this->window = NULL;
	this->dt = 0.f;
}

void GameInitialization::initGraphicsSettings()
{
	this->graphicsSettings.loadFromFile("Config/GraphicsSettings.ini");
}

void GameInitialization::initWindow()
{
	if (this->graphicsSettings.fullscreen)
		this->window = new sf::RenderWindow(
			this->graphicsSettings.resolution,
			this->graphicsSettings.title,
			sf::Style::Fullscreen,
			this->graphicsSettings.contextSettings
		);
	else
		this->window = new sf::RenderWindow(
			this->graphicsSettings.resolution,
			this->graphicsSettings.title,
			sf::Style::Titlebar | sf::Style::Close,
			this->graphicsSettings.contextSettings
		);

	this->window->setFramerateLimit(this->graphicsSettings.frameRateLimit);
	this->window->setVerticalSyncEnabled(this->graphicsSettings.verticalSync);
}

// Constructors and Destructors
GameInitialization::GameInitialization()
{
	this->initVariables();
	this->initGraphicsSettings();
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
	this->world.update(this->dt);
}

void GameInitialization::render()
{
	this->window->clear();
	this->world.render(*this->window);
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
