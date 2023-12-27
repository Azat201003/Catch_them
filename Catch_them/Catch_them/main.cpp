#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Draw.h"
#include "setting.h"

using namespace sf;
using namespace setting;
using namespace instruments;
int main()
{
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Catch them!");
    RectangleShape playerShape(Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    Player player(FIRST_PLAYER_POS);
    Draw draw;
    Clock clock;
    playerShape.setFillColor(Color::Red);

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
        draw.drawPlayer(player, &window, &playerShape);
        window.display();
    }

    return 0;
}