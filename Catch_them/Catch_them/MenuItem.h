#pragma once
#include "setting.h"
#include <SFML/Graphics.hpp>
#include <string>

class MenuItem {
public:
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void update(sf::RenderWindow* window) = 0;
};

class Button : public MenuItem {
public:
	Button(sf::Texture* aTexture,
		sf::Text aText,
		instruments::Pos texturePos,
		instruments::Pos textPos);
	void setOnClickFunction(void (*aFoo)());
	void setOnFocusFunction(void (*aFoo) (sf::Sprite*, sf::Text*));
	void setOutFocusFunction(void (*aFoo) (sf::Sprite*, sf::Text*));
	void update(sf::RenderWindow* window) override;
	void draw(sf::RenderWindow* window) override;
private:
	sf::Sprite	sprite;
	sf::Text	text;
	void (*onclick) ();
	void (*onFocus) (sf::Sprite*, sf::Text*);
	void (*outFocus) (sf::Sprite*, sf::Text*);
};

class Slider : public MenuItem {
public:
	Slider(sf::Texture* aTexture,
		sf::Texture* thumbTexture,
		instruments::Pos texturePos,
		instruments::Pos range,
		float thumbPos = 0);
	void setOnFocusFunction(void (*aFoo) (sf::Sprite*));
	void setOutFocusFunction(void (*aFoo) (sf::Sprite*));
	void setOnChangeFunction(void (*aFoo) (float value));
	void update(sf::RenderWindow* window) override;
	void draw(sf::RenderWindow* window) override;
private:
	sf::Sprite sprite;
	sf::Sprite thumbSprite;
	void (*onFocus) (sf::Sprite*);
	void (*outFocus) (sf::Sprite*);
	void (*onChange) (float value);
	instruments::Pos range;
	float thumbPos;

	bool isChanging = false;
};

