#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	this->playerTexture.loadFromFile("Texture/Player/sprite.png");
	this->bulletTexture.loadFromFile("Texture/Player/Bullet/bullet.png");
	this->enemyTexture.loadFromFile("Texture/Enemy/asteroid.png");
	this->player.push_back(
		Player
		(
			&this->playerTexture,
			Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2),
			&this->bulletTexture
		)
	);
	this->enemySpawnTimerMax = 3.f;
	this->enemySpawnTimer = enemySpawnTimerMax;

}

Game::~Game()
{

}

void Game::Update(float deltaTime)
{
	if (enemySpawnTimer <= enemySpawnTimerMax)
	{
		enemySpawnTimer += deltaTime;
	}
	if (enemySpawnTimer >= enemySpawnTimerMax)
	{
		Vector2f direction = {player[0].getPosition().x - window->getSize().x,player[0].getPosition().y };
		enemies.push_back
		(
			Enemy
			(
				&this->enemyTexture,
				direction,
				100.f,
				//Vector2f(randrange(0, 1920), randrange(0, 1080))
				Vector2f(1920-enemyTexture.getSize().x, 0)
			)
		);
		enemySpawnTimer = 0;

	}
	
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Update(deltaTime);
		for (size_t k = 0; k < player[i].getBullets().size(); k++)
		{
			player[i].getBullets()[k].Update();
			if (player[i].getBullets()[k].getPosition().x <= 0 || player[i].getBullets()[k].getPosition().x >= 1920 || player[i].getBullets()[k].getPosition().y >= 1080 || player[i].getBullets()[k].getPosition().y <= 0)
			{
				player[i].getBullets().erase(player[i].getBullets().begin() + k);
			}
		}
	}

	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].Update(deltaTime);
		if (enemies[i].getPosition().x <= 0)
		{
			enemies.erase(enemies.begin() + i);
		}
	}
}

void Game::Draw()
{
	this->window->clear();
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Draw(*this->window);
	}
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].Draw(*this->window);
	}
	this->window->display();
}
