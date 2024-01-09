#include "Object.h"

Object::Object(sf::Sprite aSprite, float aSpeed, instruments::Pos aPos) {
	sprite = aSprite;
	speed = aSpeed;
	sprite.setPosition(aPos.x, aPos.y);
}

sf::Sprite Object::getSprite() {
	return sprite;
}

float Object::getSpeed() {
	return speed;
}

void Object::move(float y) {
	sprite.move(0, y);
}