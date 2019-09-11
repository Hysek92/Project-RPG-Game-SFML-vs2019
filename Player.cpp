#include "stdafx.h"
#include "Player.h"

// Constructors and Destructors
Player::Player(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

Player::~Player()
{

}

// Functions
void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

