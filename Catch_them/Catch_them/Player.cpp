#include "Player.h"
#include "setting.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace setting;
using namespace sf;

Player::Player(instruments::Pos aPos, Sprite aSprite) {
	pos = aPos;
	sprite = aSprite;
	coins = 0;
}
void Player::move() {
	if (Keyboard::isKeyPressed(Keyboard::A) ||
		Keyboard::isKeyPressed(Keyboard::Left)) {
		pos.x -= SPEED_PLAYER;
	} 
	if (Keyboard::isKeyPressed(Keyboard::D) ||
		Keyboard::isKeyPressed(Keyboard::Right)) {
		pos.x += SPEED_PLAYER;
	}
	sprite.setPosition(pos.x, pos.y);
}

instruments::Pos Player::getPos() {
	return pos;
}
Sprite Player::getSprite() {
	return sprite;
}

void Player::addCoins(int num) {
	coins += num;
}
int Player::getCoins() {
	return coins;
}

void Player::kick(int damage) {
	hp -= damage;
	if (hp <= 0) {
		// game over
	}
}