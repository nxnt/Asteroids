#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	this->playerTexture.loadFromFile("Texture/Player/sprite.png");
	this->bulletTexture.loadFromFile("Texture/Player/Bullet/bullet.png");
	this->enemyTexture.loadFromFile("Texture/Enemy/asteroid1.png");
	this->backgroundTexture.loadFromFile("Texture/Background/background.jpg");
	this->shieldTexture.loadFromFile("Texture/Item/shield.png");
	this->shield1Texture.loadFromFile("Texture/Item/shield1.png");
	this->upgradeBulletTexture.loadFromFile("Texture/Item/upgradeBullet.png");
	this->healTexture.loadFromFile("Texture/Item/heal.png");
	this->font.loadFromFile("Font/Spantaran.ttf");
	this->font1.loadFromFile("Font/Zebulon.ttf");
	this->totalScore.setFont(font1);

	this->playerName.setFont(font);
	this->playerName.setCharacterSize(36);
	this->playerName.setFillColor(Color(0, 255, 255));

	this->showScore.setFont(font);
	this->showScore.setString("Score : ");
	this->showScore.setCharacterSize(36);
	this->showScore.setFillColor(Color(0, 255, 255));
	
	this->totalScore.setCharacterSize(30);
	this->totalScore.setFillColor(Color(0, 255, 255));
	
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

	
	background.setTexture(backgroundTexture);

	this->resetGame();
}

void Game::resetGame() {

	// รีเซ็ต Clock เพื่อเวลานับใหม่
	this->playerName.setPosition(28, 20);
	this->showScore.setPosition(1600, 18);
	this->totalScore.setPosition(1730, 25);
	this->score = 0;
	this->enemySpawnTimerMinimum = 0.5f;
	this->enemySpawnTimerDefault = 2.0f;
	this->enemySpawnTimerMax = enemySpawnTimerDefault;
	this->enemySpawnTimer = enemySpawnTimerDefault;
	this->shieldTimer = -1;
	this->upgradeBulletTimer = -1;
	this->bulletLevel = 1;
	this->resetBulletLevel = -1;
	this->hp = 100;
	this->game_time_elapsed = this->game_clock.restart();
}

Game::~Game()
{

}

void Game::spawnItem(Vector2f position)
{
	int random = randrange(1,3);
	if (random == 1)
	{
		item.push_back
		(
			Item
			(
				&this->shield1Texture,
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
	if (random == 3)
	{
		item.push_back
		(
			Item
			(
				&this->upgradeBulletTexture,
				position,
				600,
				3
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

void Game::setPlayerName(string name)
{
	this->name = name;
	this->playerName.setString(this->name);
}

void Game::Update(float deltaTime)
{
	//บันทึกเวลาที่ผ่านไปลงในตัวแปร
	this->game_time_elapsed = this->game_clock.getElapsedTime();

	//ลดดีเลย์ในการเกิดเมื่อเวลาผ่านไปเพื่อเพิ่มความยากของเกม
	int game_time_second = this->game_time_elapsed.asSeconds();
	this->enemySpawnTimerMax = this->enemySpawnTimerDefault - min(this->enemySpawnTimerDefault - this->enemySpawnTimerMinimum, (game_time_second / 100.0f));

	//ดีเลย์ในการเกิด
	if (enemySpawnTimer <= enemySpawnTimerMax)
	{
		enemySpawnTimer += deltaTime;
	}
	//สุ่มตำแหน่งเกิดของ enemy
	if (enemySpawnTimer >= enemySpawnTimerMax)
	{
		int size = randrange(1, 3);
		int behave = randrange(0, 1);
		double random_x;
		double random_y;
		if (behave) {
			random_x = randrange(0, 1920);
			random_y = double(randrange(0, 1) * 1080);
		}
		else {
			random_x = double(randrange(0, 1) * 1920);
			random_y = randrange(0, 1080);
		}

		Game::spawnAsteroid(Vector2f(random_x, random_y), 0, size);
		enemySpawnTimer = 0;
	}
	//กระพิบเมื่อเวลาของ shield ใกล้หมด
	if (shieldTimer > 0)
	{
		shieldTimer--;
		this->shield.setColor(sf::Color(255, 255, 255, 255));
		if (shieldTimer % 30 > 15 && shieldTimer < 300)
		{
			this->shield.setColor(sf::Color(255, 255, 255, 150));
		}
	}
	//เซ็ต useShield ให้เป็น F
	if (shieldTimer <= 0)
	{
		useShield = false;
	}
	if (upgradeBulletTimer > 0)
	{
		upgradeBulletTimer--;
	}
	if (upgradeBulletTimer <= 0)
	{
		player[0].setBulletLevel(0);
	}
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Update(deltaTime);
		for (int m = 0; m < item.size(); m++)
		{
			item[m].Update();
			//เช็คการเก็บไอเทม shield
			if (item[m].getGlobalBound().intersects(player[i].getGlobalBound()) && item[m].getType() == 1)
			{
				shieldTimer = 600;
				useShield = true;
				item.erase(item.begin() + m);
				
			}
			//เช็คการเก็บไอเทม Heal
			else if (item[m].getGlobalBound().intersects(player[i].getGlobalBound()) && item[m].getType() == 2)
			{
				player[i].setHp(40);
				item.erase(item.begin() + m);
			}
			//เช็คการเก็บไอเทม UpBullet
			else if (item[m].getGlobalBound().intersects(player[i].getGlobalBound()) && item[m].getType() == 3)
			{
				upgradeBulletTimer = 1000;
				player[i].setBulletLevel(bulletLevel);
				item.erase(item.begin() + m);
			}
		}
		//เมื่อมีการเก็บไอเทม shield
		if (useShield)
		{
			this->shield.setPosition(player[i].getPosition().x - 25.f, player[i].getPosition().y - 30.f);
			this->shield.setOrigin(player[i].getOrigin());
		}
		for (size_t j = 0; j < this->enemies.size(); j++)
		{
			this->enemies[j].Update(deltaTime);
			//เมื่ออุกบาทออกจากหน้าจอ
			if (enemies[j].getPosition().x <= -500 || enemies[j].getPosition().x >= 1920 + 500 ||
				enemies[j].getPosition().y <= -500 || enemies[j].getPosition().y >= 1080 + 500)
			{
				enemies.erase(enemies.begin() + j);
				break;
			}
			//เมื่อยานชนกับอุกบาท
			if (enemies[j].getGlobalBound().intersects(player[i].getGlobalBound()))
			{
				if (!useShield)
				{
					if (player[i].getInvincibility() <= 0) 
					{
						player[i].setHp(- 10);
						enemies[j].setEnemyHp(-25);
						player[i].setInvincibility(300);
						if (enemies[j].getCurrentSize() > 0) 
						{
							for (int i = 0; i < randrange(1, 3); i++) 
							{
								Game::spawnAsteroid(Vector2f(enemies[j].getPosition().x + randrange(-20, 20), enemies[j].getPosition().y + randrange(-20, 20)), randrange(0, 360), enemies[j].getCurrentSize() - 1);
							}
						}
						if (enemies[j].getEnemyHp() <= 0)
						{
							enemies.erase(enemies.begin() + j);
							break;
						}
					}
				}
				else
				{
					enemies.erase(enemies.begin() + j);
					useShield = false;
					break;
				}
			}
		}
		for (size_t k = 0; k < player[i].getBullets().size(); k++)
		{
			player[i].getBullets()[k].Update();
			//เมื่อกระสุนออกจากหน้าจอ
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
					enemies[l].setFlash();
					enemies[l].setEnemyHp(-25);

					if (enemies[l].getEnemyHp() <= 0)
					{
						score += 50 * enemies[l].getCurrentSize();
						std::stringstream strScore;
						strScore << score;
						this->totalScore.setString(strScore.str());
						int rate = randrange(1,3);
						//แตกตัว
						if (enemies[l].getCurrentSize() > 0) {
							for (int i = 0; i < randrange(2, 3); i++) {
								Game::spawnAsteroid(Vector2f(enemies[l].getPosition().x + randrange(-10, 10), enemies[l].getPosition().y + randrange(-10, 10)), randrange(0, 360), enemies[l].getCurrentSize() - 1);
							}
						}
						//สุ่มดรอปไอเทมพิเศษ
						if (enemies[l].getCurrentSize() == 1)
						{
							if (rate == 1)
							{
								Game::spawnItem(Vector2f(enemies[l].getPosition().x, enemies[l].getPosition().y));
							}
						}
						enemies.erase(enemies.begin() + l);
					}
					player[i].getBullets().erase(player[i].getBullets().begin() + k);
					break;
				}
			}
			
		}
		
	}
	for (size_t i = 0; i < item.size(); i++)
	{
		item[i].Update();
		//ลบไอเทมเมื่อหมดเวลา
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
	for (size_t i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].Draw(*this->window);
	}
	for (size_t i = 0; i < this->item.size(); i++)
	{
		this->item[i].Draw(*this->window);
	}
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Draw(*this->window);
		if (useShield)
		{
			this->window->draw(shield);
		}
	}
	this->window->draw(playerName);
	this->window->draw(showScore);
	if (score > 0)
	{
		this->window->draw(totalScore);
	}
	this->window->display();
}
