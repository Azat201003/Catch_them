#pragma once
#include "setting.h"

using namespace instruments;
class Player
{
public:
	void move(float* lastTime);
	Pos getPos();
	Player(Pos aPos);
private:
	Pos pos;
};

