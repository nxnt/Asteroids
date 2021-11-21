#pragma once
#include "Header.h"
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
	RectangleShape pauseMenu;
	RectangleShape abandonMenu;
	Font font;
	Font font1;
	Text play;
	Text logoMainMenu;
	Text logoMainMenu1;
	Text scoreBoard;
	Text myName;
	Text quit;
	Text enter;
	Text mainMenu;
	Text showName;
	Text resume;
	Text abandon;
	Text backToMenu;
	Text backToMenu1;
	Text gameOver;
	Text gameOver1;
	Text showScore;
	Text score;
	string name;
	int state;
	int totalscore;
	bool type_bounce = false;
	bool valid_name = false;
	int mouseheld;
	float mouseheldTime;
	int transition;
	float transitionCooldown;
	//menu 0
	// scoreborad 1
	//enterName 2
	// play 3
	//pause 4
	// abandon 5
	//quit 6
	
public:
	Menu(RenderWindow* window);
	~Menu();
	void menuUpdate();
	void menuDraw();
	void menuUpdateState(int state);
	string getPlayerName();
	void resetPlayerName();
	void updatePlayerName(Event& event);
	int  getState();
	void  setScore(int score);
};

