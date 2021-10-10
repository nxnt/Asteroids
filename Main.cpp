#include "Game.h"

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1920, 1080), "Asteroids", Style::Fullscreen | Style::Close);
    window.setVerticalSyncEnabled(true);
    Game game(&window);
    float deltaTime = 0.f;
    Clock clock;
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (ev.type == Event::Closed)
                window.close();
        }
        game.Update(deltaTime);
        game.Draw();
    }
    return 0;
}