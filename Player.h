#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	// Variables
	sf::Sprite sprite;

public:
	// Constructors and Destructors
	Player(sf::Texture& texture);
	virtual ~Player();

	// Functions
	void update();
	void render(sf::RenderTarget& target);
};

#endif // !PLAYER_H