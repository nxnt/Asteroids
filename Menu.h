#pragma once
#include "Header.h"
#include "ScoreList.h"
class Menu
{
private:
	RenderWindow* window;
	Event ev;
	Texture backgroundTexture;
	Texture background1Texture;
    Sprite menuBgTexture;
    Sprite menuBg1Texture;
	RectangleShape enterNameMenu;
	RectangleShape enterName1Menu;
	RectangleShape scoreboardMenu;
	RectangleShape pauseMenu;
	RectangleShape gameoverMenu;
	Font font;
	Font font1;
	Text play;
	Text logoMainMenu;
	Text logoMainMenu1;
	Text scoreBoard;
	Text leaderboard;
	Text myName;
	Text quit;
	Text enter;
	Text mainMenu;
	Text showName;
	Text resume;
	Text abandon;
	Text backToMenu;
	Text backToMenu1;
	Text back;
	Text gameOver;
	Text gameOver1;
	Text showScore;
	Text score;
	Text sbName;
	Text sbScore;
	Text playerName;
	Text playerScore;
	Text ownerID;
	string name;
	int state;
	int totalscore;
	bool type_bounce = false;
	bool valid_name = false;
	int mouseheld;
	float mouseheldTime;
	int transition;
	float transitionCooldown;
	int gameStatus;
	ScoreList* score_list;
	
public:
	Menu(RenderWindow* window, ScoreList* score_list);
	~Menu();
	void mainmenuUI();
	void enternameUI();
	void scorboardUI();
	void pauseUI();
	void gameoverUI();
	string getPlayerName();
	void resetPlayerName();
	void updatePlayerName(Event& event);
	int  getState();
	void  setScore(int score);
	void menuUpdateState(int state);
	void menuUpdate();
	void menuDraw();
	bool getGameStatus();
};

