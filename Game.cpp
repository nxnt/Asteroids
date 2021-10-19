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

void Game::spawnAsteroid(Vector2f position, double direction, int size) {

	enemies.push_back
	(
		Enemy
		(
			&this->enemyTexture,
			player[0].getPosition(),
			direction,
			100.f,
			position,
			size
		)
	);
}

void Game::Update(float deltaTime)
{
	if (enemySpawnTimer <= enemySpawnTimerMax)
	{
		enemySpawnTimer += deltaTime;
	}
	if (enemySpawnTimer >= enemySpawnTimerMax)
	{
		int behave = randrange(0, 1);
		double random_x;
		double random_y;
		if(behave) {
			random_x = randrange(0, 1920);
			random_y = randrange(0, 1) * 1080;
		}
		else {
			random_x = randrange(0, 1) * 1920;
			random_y = randrange(0, 1080);
		}

		Game::spawnAsteroid(Vector2f(random_x,random_y), 0, 3);
		enemySpawnTimer = 0;
	}
	
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Update(deltaTime);
		for (size_t j = 0; j < this->enemies.size(); j++)
		{	
			//เมื่ออุกบาทออกเกม
			this->enemies[j].Update(deltaTime);
			if (enemies[j].getPosition().x <= -500 || enemies[j].getPosition().x >= 1920 + 500 ||
			    enemies[j].getPosition().y <= -500 || enemies[j].getPosition().y >= 1080 + 500)
			{
				enemies.erase(enemies.begin() + j);
				break;
			}
			//เมื่อยานชนกับอุกบาท
			if (enemies[j].getGlobalBound().intersects(player[i].getGlobalBound()))
			{
				if(player[i].getInvincibility() <= 0) {
					player[i].setInvincibility(300);
					if (enemies[j].getCurrentSize() > 0) {
						for (int i = 0; i < randrange(3, 5); i++) {
							Game::spawnAsteroid(Vector2f(enemies[j].getPosition().x + randrange(-20, 20), enemies[j].getPosition().y + randrange(-20, 20)), randrange(0, 360), enemies[j].getCurrentSize() - 1);
						}
					}
					enemies.erase(enemies.begin() + j);
					break;
				}
			}
		}
		for (size_t k = 0; k < player[i].getBullets().size(); k++)
		{
			player[i].getBullets()[k].Update();
			if (player[i].getBullets()[k].getPosition().x <= 0 || player[i].getBullets()[k].getPosition().x >= 1920 || player[i].getBullets()[k].getPosition().y >= 1080 || player[i].getBullets()[k].getPosition().y <= 0)
			{
				player[i].getBullets().erase(player[i].getBullets().begin() + k);
				break;
			}
			for (int l = 0; l < enemies.size(); l++)
			{
				// เมื่ออุกกาบาทชนกระสุน
				if (player[i].getBullets()[k].getGlobalBound().intersects(enemies[l].getGlobalBound()))
				{
					//แตกตัว
					if(enemies[l].getCurrentSize() > 0) {
						for(int i = 0; i < randrange(3, 5); i++) {
							Game::spawnAsteroid(Vector2f(enemies[l].getPosition().x + randrange(-20, 20), enemies[l].getPosition().y + randrange(-20, 20)), randrange(0, 360), enemies[l].getCurrentSize() - 1);
						}
					}

					player[i].getBullets().erase(player[i].getBullets().begin() + k);
					enemies.erase(enemies.begin() + l);
					break;
				}
			}
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
