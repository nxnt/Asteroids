#include "Game.h"
#include "Menu.h"
int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1920, 1080), "Asteroids", Style::Fullscreen | Style::Close);
    window.setVerticalSyncEnabled(true);
    Game game(&window);
    Menu menu(&window);
    float deltaTime = 0.f;
    Clock clock;
    int action;
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
        action = menu.getState();
        switch (action)
        {
        case 0 : 
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 1:
            menu.menuUpdate();
            menu.menuDraw();
            menu.updatePlayerName(ev);
            game.setPlayerName(menu.getPlayerName());
            break;
        case 2:
            game.Update(deltaTime);
            game.Draw();
            break;
        case 3:
            window.close();
        default:
            break;
        }
        
        
    }
    return 0;
}