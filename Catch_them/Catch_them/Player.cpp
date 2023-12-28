#include "Player.h"
#include "setting.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace setting;
using namespace sf;
void Player::move() {
	if (Keyboard::isKeyPressed(Keyboard::A) ||
		Keyboard::isKeyPressed(Keyboard::Left)) {
		pos.x -= SPEED;
	} 
	if (Keyboard::isKeyPressed(Keyboard::D) ||
		Keyboard::isKeyPressed(Keyboard::Right)) {
		pos.x += SPEED;
	}
	sprite.setPosition(pos.x, pos.y);
}

Pos Player::getPos() {
	return pos;
}
Sprite Player::getSprite() {
	return sprite;
}

Player::Player(Pos aPos, Sprite aSprite) {
	pos = aPos;
	sprite = aSprite;
}