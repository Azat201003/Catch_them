#include "MenuItem.h"

Button::Button(sf::Texture aTexture, sf::Text aText, instruments::Pos pos) {
	sprite.setTexture(aTexture);
	sprite.setPosition(pos.x, pos.y);

	text	= aText   ;
}

void Button::onClick(void (*aFoo)()) {
	foo = aFoo;
}

void Button::update() {
	// òþ òþ
}

void Button::draw(sf::RenderWindow* window) {
	window->draw(sprite);
	window->draw(text);
}