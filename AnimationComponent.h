#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

class AnimationComponent
{
private:
	// Variables
	int width;
	int height;
	int startFrameX;
	int startFrameY;
	int framesX;
	int framesY;
	
	

	float timer;
	float animationTimer;

	sf::IntRect startRect;
	sf::IntRect currentRect;
	sf::IntRect endRect;

	// Initialization functions
	void initVariables();

public:
	// Constructors and Destructors
	AnimationComponent();
	virtual ~AnimationComponent();

	// Functions
	void animation(const float& dt, sf::Sprite& sprite);
};

#endif // !ANIMATIONCOMPONENT_H