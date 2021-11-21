#include "Game.h"

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
        window.clear();
        deltaTime = clock.restart().asSeconds();
        Event ev;
        while (window.pollEvent(ev))
        {

        }
        if (Keyboard::isKeyPressed(Keyboard::Escape) && menu.getState() == 2)
        {
            menu.menuUpdateState(3);
        }
        action = menu.getState();
        cout << action << endl;
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
            if (game.gameOver())
            {
                menu.menuUpdateState(4);
            }
            game.Update(deltaTime);
            game.Draw();
            break;
        case 3:
            game.Draw();
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 4:
            menu.setScore(game.getScore());
            game.Draw();
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 5:
            menu.resetPlayerName();
            game.resetGame();
            menu.menuUpdateState(0);
            break;
        case 6:
            window.close();
            break;
        default:
            break;
        }
        window.display();
  
    }
    return 0;
}