#include "stdafx.h"
#include "World.h"

// Initialization Variables
void World::initVarialbes()
{

}

void World::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/PLAYER_SHEET.png"))
		std::cerr << "ERROR::WORLD::COULD_NOT_LOAD_FONT" << "\n";
}

void World::initPlayer()
{
	this->player = new Player(this->textures["PLAYER_SHEET"]);
}

// Constructors and Destructors
World::World()
{
	this->initVarialbes();
	this->initTextures();
	this->initPlayer();
}

World::~World()
{
	delete this->player;
}

// Functions
void World::update(const float& dt)
{
	this->player->update(dt);
}

void World::render(sf::RenderTarget& target)
{
	this->player->render(target);
}
