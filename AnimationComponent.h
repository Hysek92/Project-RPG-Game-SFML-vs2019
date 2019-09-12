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
	AnimationComponent(
		int width, int heigh, 
		int start_frame_x, int start_frame_y,
		int frames_x, int frames_y,
		float animation_timer
	);
	virtual ~AnimationComponent();

	// Functions
	void playAnimation(const float& dt, sf::Sprite& sprite);
};

#endif // !ANIMATIONCOMPONENT_H