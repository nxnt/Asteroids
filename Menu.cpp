#include "Menu.h"

Menu::Menu(RenderWindow* window)
{
	this->window = window;
	this->backgroundTexture.loadFromFile("Texture/Background/menuBackground1n.png");
	this->background1Texture.loadFromFile("Texture/Background/background.jpg");
	this->font.loadFromFile("Font/Zebulon.ttf");
	this->font1.loadFromFile("Font/Spantaran.ttf");
	this->menuBgTexture.setTexture(this->backgroundTexture);
	this->menuBg1Texture.setTexture(this->background1Texture);
	this->logoMainMenu.setFont(font);
	this->logoMainMenu1.setFont(font);
	this->play.setFont(font1);
	this->scoreBoard.setFont(font1);
	this->quit.setFont(font1);
	this->myName.setFont(font1);
	this->enter.setFont(font1);
	this->mainMenu.setFont(font1);
	this->resume.setFont(font);
	this->abandon.setFont(font);
	this->backToMenu.setFont(font);
	this->backToMenu1.setFont(font);
	this->showName.setFont(font);
	this->showScore.setFont(font);
	this->score.setFont(font);
	this->gameOver.setFont(font);
	this->gameOver1.setFont(font);

	this->logoMainMenu.setString("Asteroids");
	this->logoMainMenu.setCharacterSize(100);
	this->logoMainMenu.setFillColor(Color(0,255, 255));
	this->logoMainMenu.setOrigin(this->logoMainMenu.getLocalBounds().width / 2, this->logoMainMenu.getLocalBounds().height / 2);
	this->logoMainMenu.setPosition(Vector2f (960, 300));

	this->logoMainMenu1.setString("Asteroids");
	this->logoMainMenu1.setCharacterSize(100);
	this->logoMainMenu1.setScale(1.02, 1.12);
	this->logoMainMenu1.setFillColor(Color(128, 0, 255));
	this->logoMainMenu1.setOrigin(this->logoMainMenu1.getLocalBounds().width / 2, this->logoMainMenu1.getLocalBounds().height / 2);
	this->logoMainMenu1.setPosition(Vector2f (959, 300));

	this->play.setString("PLAY");
	this->play.setCharacterSize(60);
	this->play.setOrigin(this->play.getLocalBounds().width / 2, this->play.getLocalBounds().height / 2);
	this->play.setPosition(Vector2f (960,700));
	
	this->scoreBoard.setString("SCOREBOARD");
	this->scoreBoard.setCharacterSize(60);
	this->scoreBoard.setOrigin(this->scoreBoard.getLocalBounds().width / 2, this->scoreBoard.getLocalBounds().height / 2);
	this->scoreBoard.setPosition(Vector2f (960,800));

	this->quit.setString("QUIT");
	this->quit.setCharacterSize(60);
	this->quit.setOrigin(this->quit.getLocalBounds().width / 2, this->quit.getLocalBounds().height / 2);
	this->quit.setPosition(Vector2f(960,900));

	this->myName.setString("My Name is");
	this->myName.setCharacterSize(60);
	this->myName.setFillColor(Color(255,255,255));
	this->myName.setOrigin(this->myName.getLocalBounds().width / 2, this->myName.getLocalBounds().height / 2);
	this->myName.setPosition(Vector2f(970,475));

	this->mainMenu.setString("Main Menu");
	this->mainMenu.setCharacterSize(36);
	this->mainMenu.setOrigin(this->mainMenu.getLocalBounds().width / 2, this->mainMenu.getLocalBounds().height / 2);
	this->mainMenu.setPosition(Vector2f(800,675));

	this->enter.setString("Enter");
	this->enter.setCharacterSize(36);
	this->enter.setOrigin(this->enter.getLocalBounds().width / 2, this->enter.getLocalBounds().height / 2);
	this->enter.setPosition(Vector2f(1160, 675));

	this->enterNameMenu.setSize(Vector2f(650.f, 300.f));
	this->enterNameMenu.setFillColor(Color(0, 0, 0, 200));
	this->enterNameMenu.setPosition(Vector2f(970,580));
	this->enterNameMenu.setOrigin(this->enterNameMenu.getLocalBounds().width / 2, this->enterNameMenu.getLocalBounds().height / 2);

	this->enterName1Menu.setSize(Vector2f(400.f, 50.f));
	this->enterName1Menu.setOutlineThickness(2.f);
	this->enterName1Menu.setFillColor(Color(255, 255, 255, 100));
	this->enterName1Menu.setOutlineColor(Color(131, 0, 255));
	this->enterName1Menu.setPosition(Vector2f(970,600));
	this->enterName1Menu.setOrigin(this->enterName1Menu.getLocalBounds().width / 2, this->enterName1Menu.getLocalBounds().height / 2);

	this->showName.setCharacterSize(20);
	this->showName.setFillColor(Color(0, 0, 0, 255));

	this->pauseMenu.setSize(Vector2f(525.f, 325.f));
	this->pauseMenu.setFillColor(Color(0, 0, 0, 200));
	this->pauseMenu.setPosition(Vector2f(980, 510));
	this->pauseMenu.setOrigin(this->pauseMenu.getLocalBounds().width / 2, this->pauseMenu.getLocalBounds().height / 2);

	this->resume.setString("Resume");
	this->resume.setCharacterSize(36);
	this->resume.setOrigin(this->resume.getLocalBounds().width / 2, this->resume.getLocalBounds().height / 2);
	this->resume.setPosition(Vector2f(980, 400));

	this->abandon.setString("Abandon");
	this->abandon.setCharacterSize(36);
	this->abandon.setOrigin(this->abandon.getLocalBounds().width / 2, this->abandon.getLocalBounds().height / 2);
	this->abandon.setPosition(Vector2f(980, 500));

	this->backToMenu.setString("Back to Menu");
	this->backToMenu.setCharacterSize(36);
	this->backToMenu.setOrigin(this->backToMenu.getLocalBounds().width / 2, this->backToMenu.getLocalBounds().height / 2);
	this->backToMenu.setPosition(Vector2f(980, 600));

	this->backToMenu1.setString("Back to Menu");
	this->backToMenu1.setCharacterSize(28);
	this->backToMenu1.setOrigin(this->backToMenu1.getLocalBounds().width / 2, this->backToMenu1.getLocalBounds().height / 2);
	this->backToMenu1.setPosition(Vector2f(980, 625));

	this->abandonMenu.setSize(Vector2f(550.f, 330.f));
	this->abandonMenu.setFillColor(Color(0, 0, 0, 200));
	this->abandonMenu.setPosition(Vector2f(980, 540));
	this->abandonMenu.setOrigin(this->abandonMenu.getLocalBounds().width / 2, this->abandonMenu.getLocalBounds().height / 2);

	this->gameOver.setString("Game Over");
	this->gameOver.setCharacterSize(48);
	this->gameOver.setFillColor(Color(255, 255, 0));
	this->gameOver.setOrigin(this->gameOver.getLocalBounds().width / 2, this->gameOver.getLocalBounds().height / 2);
	this->gameOver.setPosition(Vector2f(980, 440));

	this->gameOver1.setString("Game Over");
	this->gameOver1.setCharacterSize(50);
	this->gameOver1.setScale(1.0125,1.0125);
	this->gameOver1.setFillColor(Color(255, 0, 0));
	this->gameOver1.setOrigin(this->gameOver.getLocalBounds().width / 2, this->gameOver.getLocalBounds().height / 2);
	this->gameOver1.setPosition(Vector2f(975, 437.5));

	this->showScore.setString("Score :");
	this->showScore.setCharacterSize(28);
	this->showScore.setOrigin(this->showScore.getLocalBounds().width / 2, this->showScore.getLocalBounds().height / 2);
	this->showScore.setPosition(Vector2f(920, 540));

	this->score.setCharacterSize(32);
	this->score.setOrigin(this->score.getLocalBounds().width / 2, this->score.getLocalBounds().height / 2);
	this->score.setPosition(Vector2f(1040, 525));

	this->mouseheld = 0;
	this->mouseheldTime = 0.0f;
	this->transition = 0;
	this->transitionCooldown = 0.0f;
}

Menu::~Menu()
{

}

void Menu::menuDraw()
{
	if (getState() == 0)
	{
		this->window->draw(menuBgTexture);
		this->window->draw(logoMainMenu1);
		this->window->draw(logoMainMenu);
		this->window->draw(play);
		this->window->draw(scoreBoard);
		this->window->draw(quit);
	}
	else if (getState() == 1)
	{
		this->window->draw(menuBg1Texture);
		this->window->draw(logoMainMenu1);
		this->window->draw(logoMainMenu);
		this->window->draw(enterNameMenu);
		this->window->draw(enterName1Menu);
		this->window->draw(myName);
		this->window->draw(mainMenu);
		this->window->draw(enter); 
		this->window->draw(showName);
	}
	else if (getState() == 3)
	{
		this->window->draw(pauseMenu);
		this->window->draw(resume);
		this->window->draw(abandon);
		this->window->draw(backToMenu);
	}
	else if (getState() == 4)
	{
		this->window->draw(abandonMenu);
		this->window->draw(gameOver1);
		this->window->draw(gameOver);
		this->window->draw(showScore);
		this->window->draw(score);
		this->window->draw(backToMenu1);
	}
}

void Menu::menuUpdateState(int state)
{
	this->state = state;
}

string Menu::getPlayerName()
{
	return this->name;
}

void Menu::resetPlayerName()
{
	this->name = "";
	showName.setPosition(Vector2f(975, 587.5));
}

void Menu::updatePlayerName(Event& event)
{
	this->ev = event;
	if (this->name == "" && !(this->ev.type == sf::Event::TextEntered))
	{
		this->showName.setString("Enter your name");
		this->showName.setPosition(Vector2f(840, 585));
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
				showName.setPosition(Vector2f(975 - name.length() * 8.75, 587.5));
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

void Menu::setScore(int score)
{
	this->totalscore = score;
	std::stringstream strScore;
	strScore << totalscore;
	this->score.setString(strScore.str());
}

void Menu::menuUpdate()
{
	if (getState() == 0)
	{
		if (play.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->play.setScale(1.1, 1.1);
			this->play.setFillColor(Color(255, 0, 0));
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
		if (scoreBoard.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->scoreBoard.setScale(1.1, 1.1);
			this->scoreBoard.setFillColor(Color(255, 0, 0));
			/*if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(2);
			}*/
		}
		else
		{
			this->scoreBoard.setScale(1, 1);
			this->scoreBoard.setFillColor(Color(128, 255, 0));
		}
		if (quit.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->quit.setScale(1.1, 1.1);
			this->quit.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(6);
			}
		}
		else
		{
			this->quit.setScale(1, 1);
			this->quit.setFillColor(Color(128, 255, 0));
		}
	}
	else if (getState() == 1)
	{
		if (enter.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->enter.setScale(1.1, 1.1);
			this->enter.setFillColor(Color(255, 0, 0));
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
			this->mainMenu.setScale(1.1, 1.1);
			this->mainMenu.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(0);
				resetPlayerName();
			}
		}
		else
		{
			this->mainMenu.setScale(1, 1);
			this->mainMenu.setFillColor(Color(128, 255, 0));
		}
	}
	else if (getState() == 3)
	{
		if (resume.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->resume.setScale(1.1, 1.1);
			this->resume.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(2);
			}
		}
		else
		{
			this->resume.setScale(1, 1);
			this->resume.setFillColor(Color(128, 255, 0));
		}
		if (abandon.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->abandon.setScale(1.1, 1.1);
			this->abandon.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(4);
			}
		}
		else
		{
			this->abandon.setScale(1, 1);
			this->abandon.setFillColor(Color(128, 255, 0));
		}
		if (backToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->backToMenu.setScale(1.1, 1.1);
			this->backToMenu.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(0);
			}
		}
		else
		{
			this->backToMenu.setScale(1, 1);
			this->backToMenu.setFillColor(Color(128, 255, 0));
		}
	}
	else if (getState() == 4)
	{
		if (backToMenu1.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->backToMenu1.setScale(1.1, 1.1);
			this->backToMenu1.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(5);
			}
		}
		else
		{
			this->backToMenu1.setScale(1, 1);
			this->backToMenu1.setFillColor(Color(128, 255, 0));
		}
	}
}
