#pragma once
#include <SFML/Graphics.hpp>
#include "setting.h"

class Object
{
public:
	Object(sf::Sprite aSprite, float aSpeed, instruments::Pos aPos);
	sf::Sprite getSprite();
	float getSpeed();
	void move(float y);
private:
	sf::Sprite sprite;
	float speed;
};

