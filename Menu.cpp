#include "Menu.h"

Menu::Menu(RenderWindow* window)
{
	this->window = window;
	this->backgroundTexture.loadFromFile("Texture/Background/menuBackground1.png");
	this->background1Texture.loadFromFile("Texture/Background/background.jpg");
	this->font.loadFromFile("Font/Zebulon.ttf");
	this->font1.loadFromFile("Font/Spantaran.ttf");
	this->menuBgTexture.setTexture(this->backgroundTexture);
	this->menuBg1Texture.setTexture(this->background1Texture);
	this->logo.setFont(font);
	this->logo1.setFont(font);
	this->play.setFont(font1);
	this->score.setFont(font1);
	this->quit.setFont(font1);
	this->myName.setFont(font1);
	this->enter.setFont(font1);
	this->mainMenu.setFont(font1);
	this->showName.setFont(font1);

	this->logo.setString("Asteroids");
	this->logo.setCharacterSize(100);
	this->logo.setFillColor(Color(0,255, 255));
	this->logo.setOrigin(this->logo.getLocalBounds().width / 2, this->logo.getLocalBounds().height / 2);
	this->logo.setPosition(Vector2f (960, 300));

	this->logo1.setString("Asteroids");
	this->logo1.setCharacterSize(100);
	this->logo1.setScale(1.02, 1.12);
	this->logo1.setFillColor(Color(128, 0, 255));
	this->logo1.setOrigin(this->logo1.getLocalBounds().width / 2, this->logo1.getLocalBounds().height / 2);
	this->logo1.setPosition(Vector2f (959, 300));

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

	this->myName.setString("My Name is");
	this->myName.setCharacterSize(60);
	this->myName.setFillColor(Color(255,255,255));
	this->myName.setOrigin(this->myName.getLocalBounds().width / 2, this->myName.getLocalBounds().height / 2);
	this->myName.setPosition(Vector2f(970,450));

	this->mainMenu.setString("Main Menu");
	this->mainMenu.setCharacterSize(48);
	this->mainMenu.setOrigin(this->mainMenu.getLocalBounds().width / 2, this->mainMenu.getLocalBounds().height / 2);
	this->mainMenu.setPosition(Vector2f(820,715));

	this->enter.setString("Enter");
	this->enter.setCharacterSize(48);
	this->enter.setOrigin(this->enter.getLocalBounds().width / 2, this->enter.getLocalBounds().height / 2);
	this->enter.setPosition(Vector2f(1160, 715));

	this->enterNameMenu.setSize(Vector2f(650.f, 350.f));
	this->enterNameMenu.setFillColor(Color(0, 0, 0, 200));
	this->enterNameMenu.setPosition(Vector2f(970,600));
	this->enterNameMenu.setOrigin(this->enterNameMenu.getLocalBounds().width / 2, this->enterNameMenu.getLocalBounds().height / 2);

	this->enterName1Menu.setSize(Vector2f(400.f, 50.f));
	this->enterName1Menu.setFillColor(Color(255, 255, 255, 100));
	this->enterName1Menu.setPosition(Vector2f(970,600));
	this->enterName1Menu.setOrigin(this->enterName1Menu.getLocalBounds().width / 2, this->enterName1Menu.getLocalBounds().height / 2);

	this->showName.setCharacterSize(32);
	this->showName.setFillColor(Color(0, 0, 0, 255));
	this->showName.setPosition(Vector2f(800, 570));
}

Menu::~Menu()
{

}

void Menu::menuDraw()
{
	this->window->clear();
	if (getState() == 0)
	{
		this->window->draw(menuBgTexture);
		this->window->draw(logo1);
		this->window->draw(logo);
		this->window->draw(play);
		this->window->draw(score);
		this->window->draw(quit);
	}
	else if (getState() == 1)
	{
		this->window->clear();
		this->window->draw(menuBg1Texture);
		this->window->draw(logo1);
		this->window->draw(logo);
		this->window->draw(enterNameMenu);
		this->window->draw(enterName1Menu);
		this->window->draw(myName);
		this->window->draw(mainMenu);
		this->window->draw(enter);
		this->window->draw(showName);
	}
	this->window->display();
}

void Menu::menuUpdateState(int state)
{
	this->state = state;
}

string Menu::getPlayerName()
{
	return name;
}

void Menu::updatePlayerName(Event& event)
{
	this->ev = event;
	if (this->name == "" && !(this->ev.type == sf::Event::TextEntered))
	{
		this->showName.setString("Enter your name");
		this->type_bounce = 0;
		this->valid_name = 0;
	}
	else
	{
		if (event.type == sf::Event::TextEntered)
		{
			if (event.text.unicode != 32 && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->type_bounce)
			{
				this->type_bounce = 1;
				if (event.text.unicode == 8 && name.length() > 0)
				{
					name.erase(name.length() - 1);
				}
				else if (event.text.unicode < 128 && name.length() < 15 && event.text.unicode != 8)
				{
					name += static_cast<char>(event.text.unicode);
				}
				showName.setString(name);
			}
		}
		else
			this->type_bounce = 0;
		this->valid_name = 1;
	}
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
	if (enter.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->enter.setScale(1.1,1.1);
		this->enter.setFillColor(Color(255,0,0));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(2);
		}
	}
	else
	{
		this->enter.setScale(1, 1);
		this->enter.setFillColor(Color(128, 255, 0));
	}
	if (mainMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
	{
		this->mainMenu.setScale(1.1,1.1);
		this->mainMenu.setFillColor(Color(255,0,0));
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			menuUpdateState(0);
		}
	}
	else
	{
		this->mainMenu.setScale(1, 1);
		this->mainMenu.setFillColor(Color(128, 255, 0));
	}
}
