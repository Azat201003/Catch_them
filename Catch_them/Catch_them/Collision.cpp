#include "Collision.h"
#include "cstdlib"


Collision::Collision(instruments::Pos aPos, instruments::Pos aSize) {
	pos = aPos;
	size = aSize;
}
bool Collision::collisionDetect(Collision other) {
	instruments::Pos otherHalfPos(other.getSize().x / 2,
								  other.getSize().y / 2);

	instruments::Pos thisHalfPos(size.x / 2,
								 size.y / 2);

	float deltaX = abs(other.getPos().x - pos.x);
	float deltaY = abs(other.getPos().y - pos.y);

	float intersectX = deltaX - (otherHalfPos.x + thisHalfPos.x);
	float intersectY = deltaY - (otherHalfPos.y + thisHalfPos.y);

	return intersectX < 0 && intersectY < 0;
}