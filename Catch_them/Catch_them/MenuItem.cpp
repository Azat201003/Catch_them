#include "MenuItem.h"

Button::Button(sf::Texture aTexture, sf::Text aText) {
	texture = aTexture;
	text	= aText   ;
}

void Button::onClick(void (*aFoo)()) {
	foo = aFoo;
}

void Button::update() {
	// òþ òþ
}

void Button::draw(sf::RenderWindow *window) {

}