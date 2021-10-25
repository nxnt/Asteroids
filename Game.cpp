#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	this->playerTexture.loadFromFile("Texture/Player/sprite.png");
	this->bulletTexture.loadFromFile("Texture/Player/Bullet/bullet.png");
	this->enemyTexture.loadFromFile("Texture/Enemy/asteroid1.png");
	this->backgroundTexture.loadFromFile("Texture/Background/background.jpg");
	this->shieldTexture.loadFromFile("Texture/Item/shield.png");
	this->healTexture.loadFromFile("Texture/Item/heal.png");
	this->shield.setTexture(this->shieldTexture);
	this->shield.setScale(0.7, 0.7);
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
	this->shieldTimer = -1;
	background.setTexture(backgroundTexture);
}

Game::~Game()
{

}

void Game::spawnItem(Vector2f position)
{
	int random = randrange(1,2);
	if (random == 1)
	{
		item.push_back
		(
			Item
			(
				&this->shieldTexture,
				position,
				600,
				1
			)
		);
	}
	if (random == 2)
	{
		item.push_back
		(
			Item
			(
				&this->healTexture,
				position,
				600,
				2
			)
		);
	}
	
}

void Game::spawnAsteroid(Vector2f position, double direction, int size) {

	enemies.push_back
	(
		Enemy
		(
			&this->enemyTexture,
			player[0].getPosition(),
			direction,
			50.f,
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
		if (behave) {
			random_x = randrange(0, 1920);
			random_y = randrange(0, 1) * 1080;
		}
		else {
			random_x = randrange(0, 1) * 1920;
			random_y = randrange(0, 1080);
		}

		Game::spawnAsteroid(Vector2f(random_x, random_y), 0, 2);
		enemySpawnTimer = 0;
	}
	if (shieldTimer > 0)
	{
		shieldTimer--;
		this->shield.setColor(sf::Color(255, 255, 255, 255));
		if (shieldTimer % 30 > 15 && shieldTimer < 300)
		{
			this->shield.setColor(sf::Color(255, 255, 255, 150));
		}
	}
	if (shieldTimer <= 0)
	{
		useShield = false;
	}
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Update(deltaTime);
		for (int m = 0; m < item.size(); m++)
		{
			item[m].Update();
			if (item[m].getGlobalBound().intersects(player[i].getGlobalBound()) && item[m].getType() == 1)
			{
				shieldTimer = 600;
				useShield = true;
				item.erase(item.begin() + m);
				
			}
		}
		if (useShield)
		{
			this->shield.setPosition(player[i].getPosition().x - 25.f, player[i].getPosition().y - 30.f);
			this->shield.setOrigin(player[i].getOrigin());

		}
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
				if (useShield)
				{
					if (enemies[j].getCurrentSize() > 0)
					{
						for (int i = 0; i < randrange(1, 3); i++)
						{
							Game::spawnAsteroid(Vector2f(enemies[j].getPosition().x + randrange(-20, 20), enemies[j].getPosition().y + randrange(-20, 20)), randrange(0, 360), enemies[j].getCurrentSize() - 1);
						}
					}
					enemies.erase(enemies.begin() + j);
					break;
				}
				else
				{
					if (player[i].getInvincibility() <= 0) 
					{
						player[i].setInvincibility(300);
						if (enemies[j].getCurrentSize() > 0) 
						{
							for (int i = 0; i < randrange(1, 3); i++) 
							{
								Game::spawnAsteroid(Vector2f(enemies[j].getPosition().x + randrange(-20, 20), enemies[j].getPosition().y + randrange(-20, 20)), randrange(0, 360), enemies[j].getCurrentSize() - 1);
							}
						}
						enemies.erase(enemies.begin() + j);
						break;
					}
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
					int rate = randrange(6,6);
					//แตกตัว
					if (enemies[l].getCurrentSize() > 0) {
						for (int i = 0; i < randrange(2, 3); i++) {
							Game::spawnAsteroid(Vector2f(enemies[l].getPosition().x + randrange(-10, 10), enemies[l].getPosition().y + randrange(-10, 10)), randrange(0, 360), enemies[l].getCurrentSize() - 1);
						}
					}
					//สุ่มดรอปไอเทมพิเศษ
					if (enemies[l].getCurrentSize() == 1)
					{
						if (rate == 6)
						{
							Game::spawnItem(Vector2f(enemies[l].getPosition().x, enemies[l].getPosition().y));
						}
					}
					player[i].getBullets().erase(player[i].getBullets().begin() + k);
					enemies.erase(enemies.begin() + l);
					break;
				}
			}
			
		}
		
	}
	for (size_t i = 0; i < item.size(); i++)
	{
		item[i].Update();
		if (item[i].getDelay() == 0)
		{
			item.erase(item.begin() + i);
		}
	}
}

void Game::Draw()
{
	this->window->clear();
	this->window->draw(background);
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Draw(*this->window);
		if (useShield)
		{
			this->window->draw(shield);
		}
	}
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].Draw(*this->window);
	}
	for (size_t i = 0; i < this->item.size(); i++)
	{
		this->item[i].Draw(*this->window);
	}
	this->window->display();
}
