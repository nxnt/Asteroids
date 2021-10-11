#pragma once
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	
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

	void Update(float deltaTime);
	void Draw();
};

