#include "stdafx.h"
#include "Monster.h"

// Initialization functions
void Monster::initVariables()
{
	this->tileSize = 64.f;
	this->posX = 5.f * this->tileSize;
	this->posY = 5.f * this->tileSize;
	this->movementSpeed = 50.f / this->tileSize;

	this->moving = false;

	for (int i = 0; i < 4; i++)
		this->move[i] = false;
}

void Monster::initMonster()
{
	this->shape.setSize(sf::Vector2f(64.f, 64.f));
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setPosition(sf::Vector2f(this->posX, this->posY));
}

// Constructors and Destructors
Monster::Monster()
{
	this->initVariables();
	this->initMonster();
}

Monster::~Monster()
{

}

// Functions
void Monster::movement()
{
	if (this->moving)
	{
		if (this->move[LEFT] == true)
		{
			this->posX -= this->movementSpeed;
			if (this->posX <= this->nextTile.x)
			{
				this->posX = this->nextTile.x;
				this->move[LEFT] = false;
				this->moving = false;
			}
		}
		else if (this->move[RIGHT] == true)
		{
			this->posX += this->movementSpeed;
			if (this->posX >= this->nextTile.x)
			{
				this->posX = this->nextTile.x;
				this->move[RIGHT] = false;
				this->moving = false;
			}
		}
		else if (this->move[UP] == true)
		{
			this->posY -= this->movementSpeed;
			if (this->posY <= this->nextTile.y)
			{
				this->posY = this->nextTile.y;
				this->move[UP] = false;
				this->moving = false;
			}
		}
		else if (this->move[DOWN] == true)
		{
			this->posY += this->movementSpeed;
			if (this->posY >= this->nextTile.y)
			{
				this->posY = this->nextTile.y;
				this->move[DOWN] = false;
				this->moving = false;
			}
		}
	}
}

void Monster::updatePosition(const float& pos_x, const float& pos_y)
{
	if (this->posX > pos_x) // left
	{
		if (!this->moving)
		{
			this->nextTile.x = this->posX - this->tileSize;
			this->move[LEFT] = true;
			this->moving = true;
		}
	}
	else if (this->posX < pos_x) // right
	{
		if (!this->moving)
		{
			this->nextTile.x = this->posX + this->tileSize;
			this->move[RIGHT] = true;
			this->moving = true;
		}
	}
	else if (this->posY > pos_y) // up
	{
		if (!this->moving)
		{
			this->nextTile.y = this->posY - this->tileSize;
			this->move[UP] = true;
			this->moving = true;
		}
	}
	else if (this->posY < pos_y) // down
	{
		if (!this->moving)
		{
			this->nextTile.y = this->posY + this->tileSize;
			this->move[DOWN] = true;
			this->moving = true;
		}
	}
}

void Monster::update(const float& pos_x, const float& pos_y)
{
	this->updatePosition(pos_x, pos_y);
	this->movement();
	this->shape.setPosition(sf::Vector2f(this->posX, this->posY));
}

void Monster::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
