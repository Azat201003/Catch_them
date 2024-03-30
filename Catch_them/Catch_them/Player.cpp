#include "Player.h"
#include "setting.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace setting;

Player::Player(instruments::Pos aPos, sf::Sprite aSprite) {
	pos = aPos;
	sprite = aSprite;
	coins = 0;
}
Player::Player() {

}
void Player::move(float wasTime) {
	float speed = SPEED_PLAYER * wasTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		pos.x -= speed;
	} 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		pos.x += speed;
	}
	sprite.setPosition(pos.x, pos.y);
}

instruments::Pos Player::getPos() {
	return pos;
}
sf::Sprite Player::getSprite() {
	return sprite;
}

void Player::addCoins(int num, instruments::window s_window) {
	if (s_window == instruments::window::game) {
		coins += num;
	}
}
int Player::getCoins() {
	return coins;
}

void Player::kick(int damage, instruments::window s_window) {
	if(s_window == instruments::window::game) {
		hp -= damage;
		if (hp <= 0) {
			s_window = instruments::window::menu;
			coins = 0;
			hp = setting::HP;
		}
	}
}

int Player::getHp() {
	return hp;
}
