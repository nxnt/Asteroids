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
	Texture playerTexture;
	Texture bulletTexture;
	Texture enemyTexture;
	float enemySpawnTimerMax;
	float enemySpawnTimer;
	
public:

	//Constructors / Destructors
	Game(RenderWindow* window);
	~Game();

	void spawnAsteroid(Vector2f position, double direction, int size);
	void Update(float deltaTime);
	void Draw();
};

