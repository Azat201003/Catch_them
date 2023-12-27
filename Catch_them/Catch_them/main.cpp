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
    Image icon;
    Texture playerTexture;
    icon.loadFromFile("textures/icon.png");
    playerTexture.loadFromFile("textures/box.png");



    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Catch them!");
    Sprite playerSprite(playerTexture);
    Player player(FIRST_PLAYER_POS, playerSprite);
    Draw draw;
    Clock clock;

    window.setIcon(128, 128, icon.getPixelsPtr());

    float lastTime = clock.getElapsedTime().asSeconds();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        player.move(&lastTime);
        window.clear();
        draw.drawPlayer(player, &window);
        window.display();
    }

    return 0;
}