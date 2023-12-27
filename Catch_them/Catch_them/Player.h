#pragma once
#include "setting.h"
#include <SFML/Graphics.hpp>

using namespace instruments;
using namespace sf;
class Player
{
public:
	void move(float* lastTime);
	Pos getPos();
	Sprite getSprite();
	Player(Pos aPos, Sprite aSprite);
private:
	Pos pos;
	Sprite sprite;
};

