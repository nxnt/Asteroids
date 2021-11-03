#pragma once
#include "Header.h"
class Menu
{
private:
	RenderWindow* window;
	Texture backgroundTexture;
    Sprite menuBgTexture;
	Font font;
	Font font1;
	Text play;
	Text menu;
	Text menu1;
	Text score;
	Text quit;
	int state;
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
	void getPlayerName();
	int  getState();
};

