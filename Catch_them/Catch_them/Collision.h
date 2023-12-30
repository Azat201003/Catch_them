#pragma once
#include "setting.h"
class Collision
{
public:
	Collision(instruments::Pos aPos, instruments::Pos aSize);
	bool collisionDetect(Collision other);
	instruments::Pos getPos() { return pos; }
	instruments::Pos getSize() { return size; }
private:
	instruments::Pos pos;
	instruments::Pos size;
};

