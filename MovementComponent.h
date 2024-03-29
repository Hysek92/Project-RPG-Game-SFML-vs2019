#ifndef MOVEMENTCOMPONENT_H
#define MOVEMENTCOMPONENT_H

enum MOVEMENT_STATE {IDLE, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT};

class MovementComponent
{
private:
	// Variables
	float posX;
	float posY;
	float tileSize;
	sf::Vector2f nextTile;
	float movementSpeed;
	bool moving;
	bool move[5];

	// Initialization functions
	void initVariables();

public:
	// Constructors and Destructors
	MovementComponent();
	virtual ~MovementComponent();

	// Functions
	const bool getState(const short unsigned state) const;

	void movement();
	void updateImput();
	void update(sf::Sprite& sprite);
};

#endif // !MOVEMENTCOMPONENT_H