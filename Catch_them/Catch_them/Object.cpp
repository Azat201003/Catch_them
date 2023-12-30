#include "Object.h"

Object::Object(Sprite aSprite, int aSpeed, Pos aPos) {
	sprite = aSprite;
	sprite.setPosition(aPos.x, aPos.y);
}

Sprite Object::getSprite() {
	return sprite;
}

int Object::getSpeed() {
	return speed;
}

void Object::move(int y) {
	sprite.move(0, y);
}