#pragma once
#include "setting.h"
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(instruments::Pos aPos, sf::Sprite aSprite);
	Player();
	void move(float wasTime);
	instruments::Pos getPos();
	sf::Sprite getSprite();
	void addCoins(int num, instruments::window s_window);
	int getCoins();
	void kick(int damage, instruments::window s_window);
	int getHp();
private:
	instruments::Pos pos;
	sf::Sprite sprite;
	int coins;
	int hp = setting::HP;
};

