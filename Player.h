#ifndef PLAYER_H
#define PLAYER_H

#include "MovementComponent.h"
#include "AnimationComponent.h"

class MovementComponent;
class AnimationComponent;

class Player
{
private:
	// Variables
	sf::Sprite sprite;
	MovementComponent movementComponent;
	std::map<std::string, AnimationComponent*> animations;
	float animationSpeed;

	// Initialization functions
	void initVariables();

public:
	// Constructors and Destructors
	Player(sf::Texture& texture);
	virtual ~Player();

	// Functions
	void update(const float& dt);
	void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H