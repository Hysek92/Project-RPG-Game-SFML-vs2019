#ifndef GAMEINITIALIZATION_H
#define GAMEINITIALIZATION_H

class GameInitialization
{
private:
	// Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock dtClock;
	float dt;

	// Initialization functions
	void initVariables();
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