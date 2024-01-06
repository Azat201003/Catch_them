#include "MenuItem.h"

Button::Button(sf::Texture aTexture, sf::Text aText) {
	texture = aTexture;
	text	= aText   ;
}

void Button::onClick(void (*foo)()) {
	foo();
}
