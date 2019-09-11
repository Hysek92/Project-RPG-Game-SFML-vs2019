#ifndef PLAYER_H
#define PLAYER_H

#include "AnimationComponent.h"

class AnimationComponent;

class Player
{
private:
	// Variables
	sf::Sprite sprite;
	AnimationComponent animationComponent;

public:
	// Constructors and Destructors
	Player(sf::Texture& texture);
	virtual ~Player();

	// Functions
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H