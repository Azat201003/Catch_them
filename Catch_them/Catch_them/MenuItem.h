#pragma once
#include <SFML/Graphics.hpp>

class MenuItem {
	virtual void draw(sf::RenderWindow *window) = 0;
};

class Button: public MenuItem {
public:
	Button(sf::Texture aTexture, sf::Text aText);
	void onClick(void (*aFoo)());
	void update();
	void draw(sf::RenderWindow* window) override;
private:
	sf::Texture texture;
	sf::Text	text;
	void (*foo) ();
};

