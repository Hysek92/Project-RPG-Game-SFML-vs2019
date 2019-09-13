#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->animationSpeed = 10.f;
}

// Constructors and Destructors
Player::Player(sf::Texture& texture)
{
	this->initVariables();

	this->sprite.setTexture(texture);
	this->animations["IDLE"] = new AnimationComponent(64, 64, 1, 1, 9, 1, this->animationSpeed);
	this->animations["MOVE_UP"] = new AnimationComponent(64, 64, 13, 2, 16, 1, this->animationSpeed);
	this->animations["MOVE_DOWN"] = new AnimationComponent(64, 64, 1, 2, 4, 1, this->animationSpeed);
	this->animations["MOVE_LEFT"] = new AnimationComponent(64, 64, 5, 2, 8, 1, this->animationSpeed);
	this->animations["MOVE_RIGHT"] = new AnimationComponent(64, 64, 9, 2, 12, 1, this->animationSpeed);
}

Player::~Player()
{
	delete this->animations["IDLE"];
	delete this->animations["MOVE_UP"];
	delete this->animations["MOVE_DOWN"];
	delete this->animations["MOVE_LEFT"];
	delete this->animations["MOVE_RIGHT"];
}

// Functions
void Player::update(const float& dt)
{
	// Update movement
	this->movementComponent.update(this->sprite);

	// Update animation
	if (this->movementComponent.getState(IDLE))
		this->animations["IDLE"]->playAnimation(dt, this->sprite);
	else if (this->movementComponent.getState(MOVE_UP))
		this->animations["MOVE_UP"]->playAnimation(dt, this->sprite);
	else if (this->movementComponent.getState(MOVE_DOWN))
		this->animations["MOVE_DOWN"]->playAnimation(dt, this->sprite);
	else if (this->movementComponent.getState(MOVE_LEFT))
		this->animations["MOVE_LEFT"]->playAnimation(dt, this->sprite);
	else if (this->movementComponent.getState(MOVE_RIGHT))
		this->animations["MOVE_RIGHT"]->playAnimation(dt, this->sprite);

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

