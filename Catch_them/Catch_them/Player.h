#pragma once
#include "setting.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(instruments::Pos aPos, sf::Sprite aSprite);
	void move();
	instruments::Pos getPos();
	sf::Sprite getSprite();
	void addCoins(int num);
	int getCoins();
	void kick(int damage);
private:
	instruments::Pos pos;
	sf::Sprite sprite;
	int coins;
	int hp = setting::HP;
};

