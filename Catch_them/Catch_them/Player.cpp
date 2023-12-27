#include "Player.h"
#include "setting.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace setting;
using namespace sf;
void Player::move(float* lastTime) {
	Clock clock;

	float currentTime = clock.getElapsedTime().asSeconds();
	float passed = (currentTime - *lastTime) + 0.1;
	*lastTime = currentTime;

	if (Keyboard::isKeyPressed(Keyboard::A) ||
		Keyboard::isKeyPressed(Keyboard::Left)) {
		pos.x -= SPEED * passed;
	} 
	if (Keyboard::isKeyPressed(Keyboard::D) ||
		Keyboard::isKeyPressed(Keyboard::Right)) {
		pos.x += SPEED * passed;
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