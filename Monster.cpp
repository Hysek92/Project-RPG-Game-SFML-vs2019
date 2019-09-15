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
	this->texture.loadFromFile("Resources/Images/Sprites/rat.png");
	this->sprite.setTexture(this->texture);
	this->intRect = sf::IntRect(0, 0, 32, 32);
	this->sprite.setTextureRect(this->intRect);

	this->font.loadFromFile("Fonts/arial.ttf");
	this->monsterName.setFont(this->font);
	this->monsterName.setCharacterSize(12);
	this->monsterName.setFillColor(sf::Color::Green);
	this->monsterName.setString("Rat");
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
	if (
		this->posX <= pos_x + this->tileSize &&
		this->posX >= pos_x - this->tileSize &&
		this->posY <= pos_y + this->tileSize &&
		this->posY >= pos_y - this->tileSize
		)
	{
		// test
	}
	else
	{

		if (this->posX > pos_x && this->posY > pos_y)
		{
			if (pos_x - this->posX > pos_y - this->posY)
			{
				if (!this->moving)
				{
					this->nextTile.y = this->posY - this->tileSize;
					this->move[UP] = true;
					this->moving = true;
				}
			}
			else
			{
				if (!this->moving)
				{
					this->nextTile.x = this->posX - this->tileSize;
					this->move[LEFT] = true;
					this->moving = true;
				}
			}
		}
		else if (this->posX < pos_x && this->posY > pos_y)
		{
			if (pos_x - this->posX > pos_y - this->posY)
			{
				if (!this->moving)
				{
					this->nextTile.y = this->posY - this->tileSize;
					this->move[UP] = true;
					this->moving = true;
				}
			}
			else
			{
				if (!this->moving)
				{
					this->nextTile.x = this->posX + this->tileSize;
					this->move[RIGHT] = true;
					this->moving = true;
				}
			}
		}
		else if (this->posX < pos_x && this->posY < pos_y)
		{
			if (pos_x - this->posX > pos_y - this->posY)
			{
				if (!this->moving)
				{
					this->nextTile.x = this->posX + this->tileSize;
					this->move[RIGHT] = true;
					this->moving = true;
				}
			}
			else
			{
				if (!this->moving)
				{
					this->nextTile.y = this->posY + this->tileSize;
					this->move[DOWN] = true;
					this->moving = true;
				}
			}
		}
		else if (this->posX > pos_x && this->posY < pos_y)
		{
			if (pos_x - this->posX > pos_y - this->posY)
			{
				if (!this->moving)
				{
					this->nextTile.x = this->posX - this->tileSize;
					this->move[LEFT] = true;
					this->moving = true;
				}
			}
			else
			{
				if (!this->moving)
				{
					this->nextTile.y = this->posY + this->tileSize;
					this->move[DOWN] = true;
					this->moving = true;
				}
			}
		}
		else if (this->posX > pos_x && this->posY == pos_y)
		{
			if (!this->moving)
			{
				this->nextTile.x = this->posX - this->tileSize;
				this->move[LEFT] = true;
				this->moving = true;
			}
		}
		else if (this->posX == pos_x && this->posY > pos_y)
		{
			if (!this->moving)
			{
				this->nextTile.y = this->posY - this->tileSize;
				this->move[UP] = true;
				this->moving = true;
			}
		}
		else if (this->posX < pos_x && this->posY == pos_y)
		{
			if (!this->moving)
			{
				this->nextTile.x = this->posX + this->tileSize;
				this->move[RIGHT] = true;
				this->moving = true;
			}
		}
		else if (this->posX == pos_x && this->posY < pos_y)
		{
			if (!this->moving)
			{
				this->nextTile.y = this->posY + this->tileSize;
				this->move[DOWN] = true;
				this->moving = true;
			}
		}
	}
}

const sf::Vector2f Monster::getPosition()
{
	return sf::Vector2f(
		this->sprite.getPosition().x,
		this->sprite.getPosition().y
	);
}

void Monster::update(const float& pos_x, const float& pos_y)
{
	this->updatePosition(pos_x, pos_y);
	this->movement();

	this->sprite.setPosition(sf::Vector2f(
		this->posX + (this->tileSize / 2) - (this->sprite.getGlobalBounds().width / 2), 
		this->posY + (this->tileSize / 2) - (this->sprite.getGlobalBounds().height / 2)
	));

	this->monsterName.setPosition(
		this->sprite.getPosition().x + (this->sprite.getGlobalBounds().width / 2) - (this->monsterName.getGlobalBounds().width / 2),
		this->sprite.getPosition().y - 10.f
	);

	this->getPosition();
}

void Monster::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
	target.draw(this->monsterName);
}
