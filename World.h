#ifndef WORLD_H
#define WORLD_H

#include "Player.h"
#include "Monster.h"

class Player;
class Monster;

class World
{
private:
	// Variables
	std::map<std::string, sf::Texture> textures;
	sf::Font font;
	Player* player;
	Monster monster;

	// Initialization variables
	void initVarialbes();
	void initFont();
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