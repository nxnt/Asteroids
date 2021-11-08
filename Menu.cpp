#include "Menu.h"

Menu::Menu(RenderWindow* window)
{
	this->window = window;
	this->backgroundTexture.loadFromFile("Texture/Background/menuBackground1.png");
	this->font.loadFromFile("Font/Zebulon.ttf");
	this->font1.loadFromFile("Font/Spantaran.ttf");
	this->menuBgTexture.setTexture(this->backgroundTexture);
	this->menu.setFont(font);
	this->menu1.setFont(font);
	this->play.setFont(font1);
	this->score.setFont(font1);
	this->quit.setFont(font1);

	this->menu.setString("Asteroids");
	this->menu.setCharacterSize(100);
	this->menu.setFillColor(Color(0,255, 255));
	this->menu.setOrigin(this->menu.getLocalBounds().width / 2, this->menu.getLocalBounds().height / 2);
	this->menu.setPosition(Vector2f (960, 300));

	this->menu1.setString("Asteroids");
	this->menu1.setCharacterSize(100);
	this->menu1.setScale(1.02, 1.12);
	this->menu1.setFillColor(Color(128, 0, 255));
	this->menu1.setOrigin(this->menu1.getLocalBounds().width / 2, this->menu1.getLocalBounds().height / 2);
	this->menu1.setPosition(Vector2f (959, 300));

	this->play.setString("PLAY");
	this->play.setCharacterSize(60);
	this->play.setOrigin(this->play.getLocalBounds().width / 2, this->play.getLocalBounds().height / 2);
	this->play.setPosition(Vector2f (960,500));
	
	this->score.setString("SCOREBOARD");
	this->score.setCharacterSize(60);
	this->score.setOrigin(this->score.getLocalBounds().width / 2, this->score.getLocalBounds().height / 2);
	this->score.setPosition(Vector2f (960,600));

	this->quit.setString("QUIT");
	this->quit.setCharacterSize(60);
	this->quit.setOrigin(this->quit.getLocalBounds().width / 2, this->quit.getLocalBounds().height / 2);
	this->quit.setPosition(Vector2f(960,700));
	
}

Menu::~Menu()
{

}

void Menu::menuDraw()
{
	this->window->clear();
	this->window->draw(menuBgTexture);
	this->window->draw(menu1);
	this->window->draw(menu);
	this->window->draw(play);
	this->window->draw(score);
	this->window->draw(quit);
	this->window->display();
}

void Menu::menuUpdateState(int state)
{
	this->state = state;
}

void Menu::getPlayerName()
{

}

int Menu::getState()
{
	return this->state;
}

void Menu::menuUpdate()
{
	if (play.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->play.setScale(1.1,1.1);
		this->play.setFillColor(Color(255,0,0));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(1);
		}
	}
	else
	{
		this->play.setScale(1, 1);
		this->play.setFillColor(Color(128, 255, 0));
	}
	if (score.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->score.setScale(1.1,1.1);
		this->score.setFillColor(Color(255,0,0));
		/*if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(2);
		}*/
	}
	else
	{
		this->score.setScale(1, 1);
		this->score.setFillColor(Color(128, 255, 0));
	}
	if (quit.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->quit.setScale(1.1,1.1);
		this->quit.setFillColor(Color(255,0,0));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(3);
		}
	}
	else
	{
		this->quit.setScale(1, 1);
		this->quit.setFillColor(Color(128, 255, 0));
	}
}
