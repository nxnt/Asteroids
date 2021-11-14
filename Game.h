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
	Font font;
	Font font1;
	Text playerName;
	Text showScore;
	Text totalScore;
	string name;
	int score;
	bool useShield = false;
	bool useUpgradeBullet = false;
	float enemySpawnTimerDefault;
	float enemySpawnTimerMinimum;
	float enemySpawnTimerMax;
	float enemySpawnTimer;
	int  shieldTimer;
	int  upgradeBulletTimer;
	int  bulletLevel;
	int  resetBulletLevel;
	int hp;

	Clock game_clock;
	Time game_time_elapsed;
	
public:

	//Constructors / Destructors
	Game(RenderWindow* window);
	~Game();

	void resetGame();

	void spawnItem(Vector2f position);
	void spawnAsteroid(Vector2f position, double direction, int size);
	void setPlayerName(string name);
	void Update(float deltaTime);
	void Draw();
};

