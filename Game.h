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
	Sprite background;
	float enemySpawnTimerMax;
	float enemySpawnTimer;
	
public:

	//Constructors / Destructors
	Game(RenderWindow* window);
	~Game();

	void spawnItem(Vector2f position);
	void spawnAsteroid(Vector2f position, double direction, int size);
	void Update(float deltaTime);
	void Draw();
};

