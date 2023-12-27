#include "Player.h"
#include <SFML/Graphics.hpp>
#include "setting.h"
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
}

Pos Player::getPos() {
	return pos;
}

Player::Player(Pos aPos) {
	pos = aPos;
}