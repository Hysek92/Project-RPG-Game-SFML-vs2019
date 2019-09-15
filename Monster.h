#ifndef MONSTER_H
#define MONSTER_H

enum MONSTER_MOVEMENT { UP, DOWN, LEFT, RIGHT };

class Monster
{
private:
	// Variables
	float posX;
	float posY;
	float tileSize;
	sf::Vector2f nextTile;
	float movementSpeed;
	bool moving;
	bool move[4];

	sf::Sprite sprite;
	sf::Texture texture;
	sf::IntRect intRect;

	sf::Font font;
	sf::Text monsterName;

	// Initialization functions
	void initVariables();
	void initMonster();

public:
	// Constructors and Destructors
	Monster();
	virtual ~Monster();

	// Functions
	void movement();
	void updatePosition(const float& pos_x, const float& pos_y);
	const sf::Vector2f getPosition();
	void update(const float& pos_x, const float& pos_y);
	void render(sf::RenderTarget& target);
};

#endif // !MONSTER_H