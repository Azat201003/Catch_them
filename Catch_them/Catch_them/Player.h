#pragma once
#include "setting.h"
#include <SFML/Graphics.hpp>

using namespace instruments;
using namespace sf;
class Player
{
public:
	Player(Pos aPos, Sprite aSprite);
	void move();
	Pos getPos();
	Sprite getSprite();
	void addCoins(int num);
	int getCoins();
	void kick(int damage);
private:
	Pos pos;
	Sprite sprite;
	int coins;
	int hp = 10;
};

