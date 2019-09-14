#include "stdafx.h"
#include "World.h"

// Initialization Variables
void World::initVarialbes()
{

}

void World::initFont()
{
	if (!this->font.loadFromFile("Fonts/arial.ttf"))
		std::cerr << "ERROR::WORLD::COULD_NOT_LOAD_FONT" << "\n";
}

void World::initTextures()
{
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/PLAYER_SHEET.png"))
		std::cerr << "ERROR::WORLD::COULD_NOT_LOAD_TEXTURE" << "\n";
}

void World::initPlayer()
{
	this->player = new Player(this->textures["PLAYER_SHEET"], this->font);
}

// Constructors and Destructors
World::World()
{
	this->initVarialbes();
	this->initFont();
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
	this->monster.update(
		this->player->getPosition().x, 
		this->player->getPosition().y
	);
}

void World::render(sf::RenderTarget& target)
{
	this->player->render(target);
	this->monster.render(target);
}
