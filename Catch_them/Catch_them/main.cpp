#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Draw.h"
#include "setting.h"
#include "ObjectsRain.h"

using namespace sf;
using namespace setting;
using namespace instruments;
int main()
{
    // loading
    Texture playerTexture;
    Texture textureObject1;
    Texture backgroundTexture;
    Image icon;


    icon.loadFromFile("res/textures/icon.png");


    playerTexture.loadFromFile("res/textures/box.png");
    textureObject1.loadFromFile("res/textures/sweet.png");
    backgroundTexture.loadFromFile("res/textures/background.png");


    Sprite playerSprite(playerTexture);

    Sprite spriteObject1(textureObject1);


    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Catch them!");
    Player player(FIRST_PLAYER_POS, playerSprite);
    Draw draw;
    ObjectsRain OR({spriteObject1});

    window.setIcon(128, 128, icon.getPixelsPtr());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        player.move();
        OR.update(&player);
        window.clear();
        draw.drawBackground(backgroundTexture, &window);
        draw.drawObjects(OR.getObjects(), &window);
        draw.drawPlayer(player, &window);
        window.display();
    }

    return 0;
}