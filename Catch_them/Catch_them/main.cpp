#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Draw.h"
#include "setting.h"
#include "ObjectsRain.h"
#include "menuItem.h"

void start();
void quit();
void openSetting();
void updateMenuItems(Button* menuObjects[], int size, sf::RenderWindow *window) {
    for (int i = 0; i < size; i++) {
        menuObjects[i]->update(window);
    }
}

bool isOpenMenu = true;
sf::RenderWindow window(sf::VideoMode(setting::WIDTH, setting::HEIGHT), "Catch them!");

int main()
{
    // loading
    sf::Texture playerTexture;
    sf::Texture textureObject1;
    sf::Texture backgroundTexture;
    sf::Texture buttonBackgtoundTexture;

    sf::Image icon;

    sf::Font fontButtons;


    icon.loadFromFile("res/textures/icon.png");


    playerTexture.loadFromFile("res/textures/box.png");
    textureObject1.loadFromFile("res/textures/sweet.png");
    backgroundTexture.loadFromFile("res/textures/background.png");
    buttonBackgtoundTexture.loadFromFile("res/textures/buttonBackground.png");

    fontButtons.loadFromFile("res/fonts/Inter-SemiBold.ttf");

    sf::Text buttonText;

    buttonText.setFillColor(sf::Color(135, 195, 143, 255));
    buttonText.setFont(fontButtons);
    buttonText.setCharacterSize(50);

    sf::Sprite playerSprite(playerTexture);

    sf::Sprite spriteObject1(textureObject1);

    buttonText.setString("Start");
    Button button1(&buttonBackgtoundTexture, buttonText, instruments::Pos(52, 39), instruments::Pos(262, 65));
    buttonText.setString("Options");
    Button button2(&buttonBackgtoundTexture, buttonText, instruments::Pos(52, 183), instruments::Pos(221, 209));
    buttonText.setString("Quit");
    Button button3(&buttonBackgtoundTexture, buttonText, instruments::Pos(52, 327), instruments::Pos(273, 353));
    button1.onClick(start);
    button3.onClick(quit);

    Player player(setting::FIRST_PLAYER_POS, playerSprite);
    Draw draw;
    ObjectsRain OR({spriteObject1});

    MenuItem* menuItems[] = { &button1, &button2, &button3 };
    Button* buttonItems[] = { &button1, &button2, &button3 };


    window.setIcon(128, 128, icon.getPixelsPtr());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            isOpenMenu = true;
        }

        player.move();
        OR.update(&player);
        window.clear();

        draw.drawBackground(backgroundTexture, &window);
        draw.drawObjects(OR.getObjects(), &window);
        if (isOpenMenu) {
            draw.drawMenu(menuItems, 3, &window);
            updateMenuItems(buttonItems, 3, &window);
        } else {
            draw.drawPlayer(player, &window);
        }
        window.display();
    }

    return 0;
}

void start() {
    isOpenMenu = false;
}

void quit() {
    window.close();
}
