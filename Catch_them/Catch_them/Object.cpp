#include "Object.h"

Object::Object(Sprite aSprite, float aSpeed, Pos aPos) {
	sprite = aSprite;
	speed = aSpeed;
	sprite.setPosition(aPos.x, aPos.y);
}

Sprite Object::getSprite() {
	return sprite;
}

float Object::getSpeed() {
	return speed;
}

void Object::move(float y) {
	sprite.move(0, y);
}