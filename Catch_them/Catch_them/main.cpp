#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Draw.h"
#include "setting.h"

using namespace sf;
using namespace setting;
using namespace instruments;
int main()
{
    // loading
    Texture playerTexture;
    Texture textureObject1;
    Image icon;


    icon.loadFromFile("textures/icon.png");


    playerTexture.loadFromFile("res/textures/box.png");
    textureObject1.loadFromFile("res/textures/sweet.png");



    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Catch them!");
    Sprite playerSprite(playerTexture);
    Player player(FIRST_PLAYER_POS, playerSprite);
    Draw draw;

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
        window.clear();
        draw.drawPlayer(player, &window);
        window.display();
    }

    return 0;
}