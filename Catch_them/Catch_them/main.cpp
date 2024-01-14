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

void onFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText);
void outFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText);

bool isOpenMenu = true;
sf::RenderWindow window(sf::VideoMode(setting::WIDTH, setting::HEIGHT), "Catch them!");

// loading
sf::Texture playerTexture;
sf::Texture textureObject1;
sf::Texture backgroundTexture;
sf::Texture buttonBackgtoundTexture;
sf::Texture buttonBackgtoundTextureOnFocus;

sf::Image icon;
sf::Image defaultCursorImage;

sf::Font fontButtons;

int main()
{
    icon.loadFromFile("res/textures/icon.png");
    defaultCursorImage.loadFromFile("res/textures/cursor.png");


    playerTexture.loadFromFile("res/textures/box.png");
    textureObject1.loadFromFile("res/textures/sweet.png");
    backgroundTexture.loadFromFile("res/textures/background.png");
    buttonBackgtoundTexture.loadFromFile("res/textures/buttonBackground.png");
    buttonBackgtoundTextureOnFocus.loadFromFile("res/textures/buttonBackgroundOnFocus.png");


    fontButtons.loadFromFile("res/fonts/MarckScript-Regular.ttf");

    sf::Text buttonText;

    buttonText.setFillColor(sf::Color(34, 111, 84));
    buttonText.setFont(fontButtons);
    buttonText.setCharacterSize(50);

    sf::Sprite playerSprite(playerTexture);

    sf::Sprite spriteObject1(textureObject1);

    buttonText.setString("Start");
    Button button1(&buttonBackgtoundTexture, buttonText, instruments::Pos(52, 39), instruments::Pos(262, 65), defaultCursorImage);
    buttonText.setString("Options");
    Button button2(&buttonBackgtoundTexture, buttonText, instruments::Pos(52, 183), instruments::Pos(221, 209), defaultCursorImage);
    buttonText.setString("Quit");
    Button button3(&buttonBackgtoundTexture, buttonText, instruments::Pos(52, 327), instruments::Pos(273, 353), defaultCursorImage);
    button1.setOnClickFunction(start);
    button2.setOnClickFunction(openSetting);
    button3.setOnClickFunction(quit);
    button1.setOnFocusFunction(onFocusMenuButton);
    button2.setOnFocusFunction(onFocusMenuButton);
    button3.setOnFocusFunction(onFocusMenuButton);
    button1.setOutFocusFunction(outFocusMenuButton);
    button2.setOutFocusFunction(outFocusMenuButton);
    button3.setOutFocusFunction(outFocusMenuButton);

    Player player(setting::FIRST_PLAYER_POS, playerSprite);
    Draw draw;
    ObjectsRain OR({spriteObject1});

    MenuItem* menuItems[] = { &button1, &button2, &button3 };
    Button* buttonItems[] = { &button1, &button2, &button3 };


    window.setIcon(128, 128, icon.getPixelsPtr());

    sf::Clock startFrame;
    float wasTime;

    while (window.isOpen())
    {
        if (window.hasFocus()) {
            wasTime = startFrame.getElapsedTime().asMicroseconds();
            setting::SPEED_FALLING += wasTime * 0.001 * 0.0001;
            setting::SPEED_PLAYER += wasTime * 0.0005 * 0.0001;
            startFrame.restart();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                isOpenMenu = true;
            }

            player.move(wasTime);
            OR.update(&player, wasTime, &isOpenMenu);
            window.clear();

            draw.drawBackground(backgroundTexture, &window);
            draw.drawObjects(OR.getObjects(), &window);
            if (isOpenMenu) {
                draw.drawMenu(menuItems, 3, &window);
                updateMenuItems(buttonItems, 3, &window);
            }
            else {
                draw.drawPlayer(player, &window);
            }
            window.display();
        }
    }

    return 0;
}

void start() {
    isOpenMenu = false;
}

void openSetting() {

}

void quit() {
    window.close();
}

void onFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText) {
    aSprite->setTexture(buttonBackgtoundTextureOnFocus);
    aText->setOutlineThickness(2);
    aText->setOutlineColor(sf::Color(244, 240, 187));
}

void outFocusMenuButton(sf::Sprite* aSprite, sf::Text* aText) {
    aSprite->setTexture(buttonBackgtoundTexture);
    aText->setOutlineThickness(0);
}