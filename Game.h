#pragma once
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	
	Vector2f position;
 	RenderWindow* window;
	vector<Player> player;
	vector<Enemy> enemies;
	vector<Item> item;
	Texture playerTexture;
	Texture bulletTexture;
	Texture enemyTexture;
	Texture backgroundTexture;
	Texture shieldTexture;
	Texture shield1Texture;
	Texture healTexture;
	Texture upgradeBulletTexture;
	Sprite background;
	Sprite shield;
	bool useShield = false;
	bool useUpgradeBullet = false;
	float enemySpawnTimerMax;
	float enemySpawnTimer;
	int  shieldTimer;
	int  upgradeBulletTimer;
	int  bulletLevel;
	int  resetBulletLevel;
	int hp;
	
public:

	//Constructors / Destructors
	Game(RenderWindow* window);
	~Game();

	void spawnItem(Vector2f position);
	void spawnAsteroid(Vector2f position, double direction, int size);
	void Update(float deltaTime);
	void Draw();
};

