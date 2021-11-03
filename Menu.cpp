#include "Menu.h"

Menu::Menu(RenderWindow* window)
{
	this->window = window;
	this->backgroundTexture.loadFromFile("Texture/Background/menuBackground1.png");
	this->font.loadFromFile("Font/ZealotOutline.ttf");
	this->menuBgTexture.setTexture(this->backgroundTexture);
	this->menu.setFont(font);
	this->play.setFont(font);
	this->score.setFont(font);
	this->quit.setFont(font);

	this->menu.setString("Asteroids");
	this->menu.setCharacterSize(100);
	this->menu.setFillColor(Color(255, 0, 255));
	this->menu.setOrigin(this->menu.getLocalBounds().width / 2, this->menu.getLocalBounds().height / 2);
	this->menu.setPosition(Vector2f (960, 300));

	this->play.setString("PLAY");
	this->play.setCharacterSize(48);
	this->play.setFillColor(Color(51, 255, 51));
	this->play.setOrigin(this->play.getLocalBounds().width / 2, this->play.getLocalBounds().height / 2);
	this->play.setPosition(Vector2f (960,500));
	
	this->score.setString("ScoreBoard");
	this->score.setCharacterSize(48);
	this->score.setFillColor(Color(51, 255, 51));
	this->score.setOrigin(this->score.getLocalBounds().width / 2, this->score.getLocalBounds().height / 2);
	this->score.setPosition(Vector2f (960,600));

	this->quit.setString("Quit");
	this->quit.setCharacterSize(48);
	this->quit.setFillColor(Color(51, 255, 51));
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

int Menu::getState()
{
	return this->state;
}

void Menu::menuUpdate()
{
	if (play.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->play.setScale(1.1,1.1);
		this->play.setFillColor(Color(255, 51, 51));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(1);
		}
	}
	else
	{
		this->play.setScale(1, 1);
		this->play.setFillColor(Color(51, 255, 51));
	}
	if (score.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->score.setScale(1.1,1.1);
		this->score.setFillColor(Color(255, 51, 51));
		/*if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(2);
		}*/
	}
	else
	{
		this->score.setScale(1, 1);
		this->score.setFillColor(Color(51, 255, 51));
	}
	if (quit.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->quit.setScale(1.1,1.1);
		this->quit.setFillColor(Color(255, 51, 51));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(3);
		}
	}
	else
	{
		this->quit.setScale(1, 1);
		this->quit.setFillColor(Color(51, 255, 51));
	}
}
