#include "Game.h"

int main()
{
    srand(time(NULL));
    RenderWindow window(VideoMode(1920, 1080), "Asteroids", Style::Fullscreen | Style::Close);
    window.setVerticalSyncEnabled(true);
    ScoreList score_list("highscore.txt");
    score_list.loadFile();
    Game game(&window, &score_list);
    Menu menu(&window, &score_list);
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
        if (Keyboard::isKeyPressed(Keyboard::Escape) && menu.getState() == 6 )
        {
            menu.menuUpdateState(3);
        }
        action = menu.getState();
        switch (action)
        {
        case 0 :  //main menu
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 1:   //entr name
            menu.menuUpdate();
            menu.menuDraw();
            menu.updatePlayerName(ev);
            game.setPlayerName(menu.getPlayerName());
            break;
        case 2:  //scoreboard
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 3:  //pause menu
            game.Draw();
            if (game.gameOver(menu.getGameStatus()))
            {
                menu.setGameStatus(false);
                menu.menuUpdateState(4);
            }
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 4:  //game over menu
            menu.setScore(game.getScore());
            game.Draw();
            menu.menuUpdate();
            menu.menuDraw();
            break;
        case 5: //reset gane
            menu.resetPlayerName();
            game.resetGame();
            menu.menuUpdateState(0);
            break;
        case 6: //start game
            if (game.gameOver(NULL))
            {
                menu.menuUpdateState(4);
            }
            game.Update(deltaTime);
            game.Draw();
            break;
        case 7: //close game
            window.close();
            break;
        case 8:
            menu.menuUpdate();
            menu.menuDraw();
        default:
            break;
        }
        window.display();
  
    }
    score_list.saveFile();
    return 0;
}