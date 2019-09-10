#ifndef GAMEINITIALIZATION_H
#define GAMEINITIALIZATION_H

#include "GraphicsSettings.h"

class GraphicsSettings;

class GameInitialization
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock dtClock;
	float dt;

	GraphicsSettings graphicsSettings;

	// Initialization functions
	void initVariables();
	void initGraphicsSettings();
	void initWindow();

public:
	// Constructors and Destructors
	GameInitialization();
	virtual ~GameInitialization();

	// Functions
	void updateDt();
	void updateEvent();
	void update();

	void render();

	void runApplications();
	void endApplications();
};

#endif // !GAMEINITIALIZATION_H