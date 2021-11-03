#pragma once
#include "Header.h"
class Menu
{
private:
	RenderWindow* window;
	Texture backgroundTexture;
    Sprite menuBgTexture;
	Font font;
	Text play;
	Text menu;
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
	int  getState();
};

