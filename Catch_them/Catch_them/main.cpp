#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Draw.h"
#include "setting.h"
#include "ObjectsRain.h"
#include "menuItem.h"

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

    buttonText.setFont(fontButtons);
    buttonText.setCharacterSize(50);

    sf::Sprite playerSprite(playerTexture);

    sf::Sprite spriteObject1(textureObject1);

    buttonText.setString("start");
    Button button1(buttonBackgtoundTexture, buttonText, instruments::Pos(52, 39));
    buttonText.setString("setting");
    Button button2(buttonBackgtoundTexture, buttonText, instruments::Pos(52, 183));
    buttonText.setString("quit");
    Button button3(buttonBackgtoundTexture, buttonText, instruments::Pos(52, 327));

    sf::RenderWindow window(sf::VideoMode(setting::WIDTH, setting::HEIGHT), "Catch them!");
    Player player(setting::FIRST_PLAYER_POS, playerSprite);
    Draw draw;
    ObjectsRain OR({spriteObject1});

    //vector<MenuItem> menuItems{ button1, button2, button3 };

    window.setIcon(128, 128, icon.getPixelsPtr());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.move();
        OR.update(&player);
        window.clear();
        draw.drawBackground(backgroundTexture, &window);
        draw.drawObjects(OR.getObjects(), &window);
        draw.drawPlayer(player, &window);
        button1.draw(&window);
        window.display();
    }

    return 0;
}