#include "Menu.h"

Menu::Menu(RenderWindow* window, ScoreList* score_list)
{
	this->window = window;
	this->score_list = score_list;
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
	this->myName.setFont(font);
	this->enter.setFont(font);
	this->mainMenu.setFont(font);
	this->resume.setFont(font);
	this->abandon.setFont(font);
	this->back.setFont(font1);
	this->backToMenu.setFont(font);
	this->backToMenu1.setFont(font);
	this->showName.setFont(font);
	this->showScore.setFont(font);
	this->score.setFont(font);
	this->sbName.setFont(font);
	this->sbScore.setFont(font);
	this->gameOver.setFont(font);
	this->gameOver1.setFont(font);
	this->leaderboard.setFont(font);
	this->playerName.setFont(font);
	this->playerScore.setFont(font);
	this->mouseheld = 0;
	this->mouseheldTime = 0.0f;
	this->transition = 0;
	this->transitionCooldown = 0.0f;
	mainmenuUI();
	enternameUI();
	scorboardUI();
	pauseUI();
	gameoverUI();
}

Menu::~Menu()
{

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
				menuUpdateState(1);	//go to case 1 : "enter name"
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
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(2);	//go to case 2 : "scoreboard"
			}
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
				menuUpdateState(7);	//go to case 7 : "quit"
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
				menuUpdateState(6);	//go to case 6 : "star game"
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
				menuUpdateState(0);	//go to case 0 : "main menu"
				resetPlayerName();
			}
		}
		else
		{
			this->mainMenu.setScale(1, 1);
			this->mainMenu.setFillColor(Color(128, 255, 0));
		}
	}
	else if (getState() == 2)
	{
		if (back.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->back.setScale(1.1, 1.1);
			this->back.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				this->logoMainMenu.setPosition(Vector2f(960, 300));
				this->logoMainMenu1.setPosition(Vector2f(959, 300));
				menuUpdateState(0);	//go to case 0 : "main menu"
			}
		}
		else
		{
			this->back.setScale(1, 1);
			this->back.setFillColor(Color(128, 255, 0));
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
				menuUpdateState(6);	//go to case 6 : "start game"
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
				this->gameStatus = true; //go to case 4 : "game over menu"
			}
		}
		else
		{
			this->gameStatus = false;
			this->abandon.setScale(1, 1);
			this->abandon.setFillColor(Color(128, 255, 0));
		}
		if (backToMenu.getGlobalBounds().contains(Vector2f(Mouse::getPosition())))
		{
			this->backToMenu.setScale(1.1, 1.1);
			this->backToMenu.setFillColor(Color(255, 0, 0));
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				menuUpdateState(0);	//go to case 0 : "main menu"
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
				menuUpdateState(5);	//go to case 5 : "reset game"
			}
		}
		else
		{
			this->backToMenu1.setScale(1, 1);
			this->backToMenu1.setFillColor(Color(128, 255, 0));
		}
	}
}

void Menu::menuDraw()
{
	if (getState() == 0)	//main menu
	{
		this->window->draw(menuBgTexture);
		this->window->draw(logoMainMenu1);
		this->window->draw(logoMainMenu);
		this->window->draw(play);
		this->window->draw(scoreBoard);
		this->window->draw(quit);
	}
	else if (getState() == 1)	//enter name
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
	else if (getState() == 2)	//scoreboard
	{
		this->window->draw(menuBg1Texture);
		this->window->draw(scoreboardMenu);
		this->window->draw(leaderboard);
		this->window->draw(sbName);
		this->window->draw(sbScore);
		int max_entry = 5;
		for (int i = 0; i < this->score_list->get().size(); i++) 
		{
			if (i == max_entry)
			{
				break;
			}
			std::string name_to_show = this->score_list->get().at(i).getName();
			int score = this->score_list->get().at(i).getScore();

			this->playerName.setString(name_to_show);
			this->playerName.setPosition(650, 420 + (i * 75));
			this->window->draw(playerName);
			
			this->playerScore.setString(std::to_string(score));
			this->playerScore.setPosition(1090, 420 + (i * 75));
			this->window->draw(playerScore);
		}
		this->window->draw(back);
	}
	else if (getState() == 3)	//pause menu
	{
		this->window->draw(pauseMenu);
		this->window->draw(resume);
		this->window->draw(abandon);
		this->window->draw(backToMenu);
	}
	else if (getState() == 4)	//game over menu
	{
		this->window->draw(gameoverMenu);
		this->window->draw(gameOver1);
		this->window->draw(gameOver);
		this->window->draw(showScore);
		this->window->draw(score);
		this->window->draw(backToMenu1);
	}
}

bool Menu::getGameStatus()
{
	return this->gameStatus;
}

void Menu::mainmenuUI()
{
	this->logoMainMenu.setString("Asteroids");
	this->logoMainMenu.setCharacterSize(140);
	this->logoMainMenu.setFillColor(Color(0, 255, 255));
	this->logoMainMenu.setOrigin(this->logoMainMenu.getLocalBounds().width / 2, this->logoMainMenu.getLocalBounds().height / 2);
	this->logoMainMenu.setPosition(Vector2f(980, 250));

	this->logoMainMenu1.setString("Asteroids");
	this->logoMainMenu1.setCharacterSize(140);
	this->logoMainMenu1.setScale(1.02, 1.12);
	this->logoMainMenu1.setOutlineThickness(1);
	this->logoMainMenu1.setFillColor(Color(128, 0, 255));
	this->logoMainMenu1.setOutlineColor(Color(255, 255, 255));
	this->logoMainMenu1.setOrigin(this->logoMainMenu1.getLocalBounds().width / 2, this->logoMainMenu1.getLocalBounds().height / 2);
	this->logoMainMenu1.setPosition(Vector2f(979, 250));

	this->play.setString("PLAY");
	this->play.setCharacterSize(60);
	this->play.setOrigin(this->play.getLocalBounds().width / 2, this->play.getLocalBounds().height / 2);
	this->play.setPosition(Vector2f(960, 700));

	this->scoreBoard.setString("SCOREBOARD");
	this->scoreBoard.setCharacterSize(60);
	this->scoreBoard.setOrigin(this->scoreBoard.getLocalBounds().width / 2, this->scoreBoard.getLocalBounds().height / 2);
	this->scoreBoard.setPosition(Vector2f(960, 800));

	this->quit.setString("QUIT");
	this->quit.setCharacterSize(60);
	this->quit.setOrigin(this->quit.getLocalBounds().width / 2, this->quit.getLocalBounds().height / 2);
	this->quit.setPosition(Vector2f(960, 900));
}

void Menu::enternameUI()
{
	this->myName.setString("My Name is");
	this->myName.setCharacterSize(48);
	this->myName.setFillColor(Color(255, 255, 255));
	this->myName.setOrigin(this->myName.getLocalBounds().width / 2, this->myName.getLocalBounds().height / 2);
	this->myName.setPosition(Vector2f(970, 475));

	this->mainMenu.setString("Menu");
	this->mainMenu.setCharacterSize(32);
	this->mainMenu.setOrigin(this->mainMenu.getLocalBounds().width / 2, this->mainMenu.getLocalBounds().height / 2);
	this->mainMenu.setPosition(Vector2f(780, 675));

	this->enter.setString("Enter");
	this->enter.setCharacterSize(32);
	this->enter.setOrigin(this->enter.getLocalBounds().width / 2, this->enter.getLocalBounds().height / 2);
	this->enter.setPosition(Vector2f(1160, 675));

	this->enterNameMenu.setSize(Vector2f(650.f, 300.f));
	this->enterNameMenu.setFillColor(Color(0, 0, 0, 200));
	this->enterNameMenu.setPosition(Vector2f(970, 580));
	this->enterNameMenu.setOrigin(this->enterNameMenu.getLocalBounds().width / 2, this->enterNameMenu.getLocalBounds().height / 2);

	this->enterName1Menu.setSize(Vector2f(400.f, 50.f));
	this->enterName1Menu.setOutlineThickness(2.f);
	this->enterName1Menu.setFillColor(Color(255, 255, 255, 100));
	this->enterName1Menu.setOutlineColor(Color(131, 0, 255));
	this->enterName1Menu.setPosition(Vector2f(970, 600));
	this->enterName1Menu.setOrigin(this->enterName1Menu.getLocalBounds().width / 2, this->enterName1Menu.getLocalBounds().height / 2);

	this->showName.setCharacterSize(20);
	this->showName.setFillColor(Color(0, 0, 0, 255));
}

void Menu::scorboardUI()
{
	this->leaderboard.setString("HIGH SCORE");
	this->leaderboard.setCharacterSize(100);
	this->leaderboard.setOutlineThickness(10);
	this->leaderboard.setFillColor(Color(237, 0, 80, 255));
	this->leaderboard.setOutlineColor(Color(0,0,0, 255));
	this->leaderboard.setOrigin(this->leaderboard.getLocalBounds().width / 2, this->leaderboard.getLocalBounds().height / 2);
	this->leaderboard.setPosition(Vector2f(980, 150));

	this->playerName.setCharacterSize(32);
	this->playerScore.setCharacterSize(32);

	this->sbName.setString("Name");
	this->sbName.setCharacterSize(48);
	this->sbName.setFillColor(Color(235, 245, 10, 255)); 
	this->sbScore.setString("Score");
	this->sbScore.setCharacterSize(48);
	this->sbScore.setFillColor(Color(235, 245, 10, 255));
	this->sbName.setPosition(720, 320);
	this->sbScore.setPosition(1050, 320);

	this->back.setString("BACK");
	this->back.setCharacterSize(40);
	this->back.setOrigin(this->back.getLocalBounds().width / 2, this->back.getLocalBounds().height / 2);
	this->back.setPosition(Vector2f(980, 850));

	this->scoreboardMenu.setSize(Vector2f(800.f, 600.f));
	this->scoreboardMenu.setOutlineThickness(2.5);
	this->scoreboardMenu.setOutlineColor(Color(0, 237, 157, 255));
	this->scoreboardMenu.setFillColor(Color(0, 0, 0, 200));
	this->scoreboardMenu.setPosition(Vector2f(970, 600));
	this->scoreboardMenu.setOrigin(this->scoreboardMenu.getLocalBounds().width / 2, this->scoreboardMenu.getLocalBounds().height / 2);
}

void Menu::pauseUI()
{
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
}

void Menu::gameoverUI()
{
	this->gameoverMenu.setSize(Vector2f(550.f, 330.f));
	this->gameoverMenu.setFillColor(Color(0, 0, 0, 200));
	this->gameoverMenu.setPosition(Vector2f(980, 540));
	this->gameoverMenu.setOrigin(this->gameoverMenu.getLocalBounds().width / 2, this->gameoverMenu.getLocalBounds().height / 2);

	this->gameOver.setString("Game Over");
	this->gameOver.setCharacterSize(48);
	this->gameOver.setFillColor(Color(255, 255, 0));
	this->gameOver.setOrigin(this->gameOver.getLocalBounds().width / 2, this->gameOver.getLocalBounds().height / 2);
	this->gameOver.setPosition(Vector2f(980, 440));

	this->gameOver1.setString("Game Over");
	this->gameOver1.setCharacterSize(50);
	this->gameOver1.setScale(1.0125, 1.0125);
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

	this->backToMenu1.setString("Back to Menu");
	this->backToMenu1.setCharacterSize(28);
	this->backToMenu1.setOrigin(this->backToMenu1.getLocalBounds().width / 2, this->backToMenu1.getLocalBounds().height / 2);
	this->backToMenu1.setPosition(Vector2f(980, 625));
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

