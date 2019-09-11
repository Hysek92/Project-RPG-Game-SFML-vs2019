#include "stdafx.h"
#include "AnimationComponent.h"

void AnimationComponent::initVariables()
{
	this->width = 64;
	this->height = 64;
	this->startFrameX = 1;
	this->startFrameY = 1;
	this->framesX = 9;
	this->framesY = 1;
	

	this->timer = 0.f;
	this->animationTimer = 10.f;

	this->startRect = sf::IntRect(
		(this->startFrameX * this->width) - this->width, 
		(this->startFrameY * this->height) - this->height, 
		this->width, this->height
	);

	this->currentRect = this->startRect;

	this->endRect = sf::IntRect(
		(this->framesX * this->width) - this->width, 
		(this->framesY * this->height) - this->height, 
		this->width, this->height
	);
}

// Constructors and Destructors
AnimationComponent::AnimationComponent()
{
	this->initVariables();
}

AnimationComponent::~AnimationComponent()
{

}

// Functions
void AnimationComponent::animation(const float& dt, sf::Sprite& sprite)
{
	this->timer += 100 * dt;
	if (this->timer >= this->animationTimer)
	{
		if (this->currentRect.left == this->endRect.left)
			this->currentRect.left = this->startRect.left;
		else
			this->currentRect.left += this->width;
			
		sprite.setTextureRect(this->currentRect);

		this->timer = 0.f;
	}
}

