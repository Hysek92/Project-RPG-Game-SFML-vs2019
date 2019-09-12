#include "stdafx.h"
#include "AnimationComponent.h"

void AnimationComponent::initVariables()
{
	this->timer = 0.f;
}

// Constructors and Destructors
AnimationComponent::AnimationComponent(
	int width, int height,
	int start_frame_x, int start_frame_y,
	int frames_x, int frames_y,
	float animation_timer
)
	: width(width), height(height), 
	startFrameX(start_frame_x), startFrameY(start_frame_y),
	framesX(frames_x), framesY(frames_y),
	animationTimer(animation_timer)
{
	this->initVariables();

	this->startRect = sf::IntRect((this->startFrameX * this->width) - this->width, (this->startFrameY * this->height) - this->height, this->width, this->height);
	this->currentRect = this->startRect;
	this->endRect = sf::IntRect((this->framesX * this->width) - this->width, (this->framesY * this->height) - this->height, this->width, this->height);
}

AnimationComponent::~AnimationComponent()
{

}

// Functions
void AnimationComponent::playAnimation(const float& dt, sf::Sprite& sprite)
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

