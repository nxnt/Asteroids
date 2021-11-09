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
	Font font;
	Font font1;
	Text play;
	Text logo;
	Text logo1;
	Text score;
	Text myName;
	Text quit;
	Text enter;
	Text mainMenu;
	Text showName;
	string name;
	int state;
	bool type_bounce = false;
	bool valid_name = false;
	//menu 0
	//play 1
	//score 2
	//quit 3
	
public:
	Menu(RenderWindow* window);
	~Menu();
	void menuUpdate();
	void menuDraw();
	void menuUpdateState(int state);
	string getPlayerName();
	void updatePlayerName(Event& event);
	int  getState();
};

