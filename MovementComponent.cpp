#include "stdafx.h"
#include "MovementComponent.h"

// Initialization functiuons
void MovementComponent::initVariables()
{
	this->posX = 0.f;
	this->posY = 0.f;
	this->tileSize = 64.f;
	this->movementSpeed = 100.f / this->tileSize;
	this->moving = false;
	for (int i = 0; i < 5; i++)
		this->move[i] = false;
}

// Constructors and Destructors
MovementComponent::MovementComponent()
{
	this->initVariables();
}

MovementComponent::~MovementComponent()
{

}

const bool MovementComponent::getState(const short unsigned state) const
{
	switch (state)
	{
	case IDLE:
		if (this->posX == this->nextTile.x && this->posY == this->nextTile.y)
			return true;
		break;
	case MOVE_UP:
		if (this->posY > this->nextTile.y)
			return true;
		break;
	case MOVE_DOWN:
		if (this->posY < this->nextTile.y)
			return true;
		break;
	case MOVE_LEFT:
		if (this->posX > this->nextTile.x)
			return true;
		break;
	case MOVE_RIGHT:
		if ((this->posX < this->nextTile.x))
			return true;
		break;
	}
	return false;
}

// Functions
void MovementComponent::movement()
{
	if (this->moving)
	{
		if (this->move[MOVE_UP] == true)
		{
			this->posY -= this->movementSpeed;
			if (this->posY <= this->nextTile.y)
			{
				this->posY = this->nextTile.y;
				this->move[MOVE_UP] = false;
				this->moving = false;
			}
		}
		else if (this->move[MOVE_DOWN] == true)
		{
			this->posY += this->movementSpeed;
			if (this->nextTile.y <= this->posY)
			{
				this->posY = this->nextTile.y;
				this->move[MOVE_DOWN] = false;
				this->moving = false;
			}
		}
		else if (this->move[MOVE_LEFT] == true)
		{
			this->posX -= this->movementSpeed;
			if (this->nextTile.x >= this->posX)
			{
				this->posX = this->nextTile.x;
				this->move[MOVE_LEFT] = false;
				this->moving = false;
			}
		}
		else if (this->move[MOVE_RIGHT] == true)
		{
			this->posX += this->movementSpeed;
			if (this->nextTile.x <= this->posX)
			{
				this->posX = this->nextTile.x;
				this->move[MOVE_RIGHT] = false;
				this->moving = false;
			}
		}
	}
}

void MovementComponent::updateImput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (!this->moving)
		{
			this->nextTile.y = this->posY - this->tileSize;
			this->move[MOVE_UP] = true;
			this->moving = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (!this->moving)
		{
			this->nextTile.y = this->posY + this->tileSize;
			this->move[MOVE_DOWN] = true;
			this->moving = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (!this->moving)
		{
			this->nextTile.x = this->posX - this->tileSize;
			this->move[MOVE_LEFT] = true;
			this->moving = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (!this->moving)
		{
			this->nextTile.x = this->posX + this->tileSize;
			this->move[MOVE_RIGHT] = true;
			this->moving = true;
		}
	}
}

void MovementComponent::update(sf::Sprite& sprite)
{
	this->updateImput();
	this->movement();
	sprite.setPosition(this->posX, this->posY);
}
 
