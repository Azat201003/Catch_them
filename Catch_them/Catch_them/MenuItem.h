#pragma once
#include "setting.h"
#include <SFML/Graphics.hpp>

class MenuItem {
public:
	virtual void draw(sf::RenderWindow* window) = 0;
};

class Button : public MenuItem {
public:
	Button(sf::Texture* aTexture, sf::Text aText, instruments::Pos texturePos, instruments::Pos textPos);
	void setOnClickFunction(void (*aFoo)());
	void setOnFocusFunction(void (*aFoo) (sf::Sprite*, sf::Text*));
	void setOutFocusFunction(void (*aFoo) (sf::Sprite*, sf::Text*));
	void update(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window) override;
private:
	sf::Sprite	sprite	;
	sf::Text	text	;
	sf::Cursor	cursor	;
	void (*onclick) ()	;
	void (*onFocus) (sf::Sprite*, sf::Text*);
	void (*outFocus) (sf::Sprite*, sf::Text*);
};

