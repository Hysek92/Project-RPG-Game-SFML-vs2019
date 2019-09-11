#ifndef WORLD_H
#define WORLD_H

#include "Player.h"

class Player;

class World
{
private:
	// Variables
	std::map<std::string, sf::Texture> textures;

	Player* player;

	// Initialization variables
	void initVarialbes();
	void initTextures();

	void initPlayer();

public:
	// Constructors and Destructors
	World();
	virtual ~World();

	// Functions
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

#endif // !WORLD_H