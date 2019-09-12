#include "stdafx.h"
#include "Player.h"

// Constructors and Destructors
Player::Player(sf::Texture& texture)
{
	this->sprite.setTexture(texture);
	this->animations["IDLE"] = new AnimationComponent(64, 64, 1, 1, 9, 1, 20.f);
}

Player::~Player()
{
	delete this->animations["IDLE"];
}

// Functions
void Player::update(const float& dt)
{
	this->movementComponent.update(this->sprite);
	this->animations["IDLE"]->playAnimation(dt, this->sprite);


	std::cout << this->movementComponent.movementState() << "\n";
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

