#pragma once
#include <SFML/Graphics.hpp>
#include "setting.h"

class Object
{
public:
	Object(sf::Sprite aSprite, float aSpeed, instruments::Pos aPos);
	sf::Sprite getSprite();
	float getSpeed();
	void setSpeed(float speed) { this->speed = speed; };
	void setPosition(instruments::Pos pos) { this->sprite.setPosition(pos.x, pos.y); };
	void move(float y);
private:
	sf::Sprite sprite;
	float speed;
};

