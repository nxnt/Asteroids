#pragma once
#include "Item.h"

class Enemy
{
private:
	Texture* texture;
	double direction;
	float speed;
	Vector2f position;
	Sprite sprite;
	double s;
	double offset_direction;
	float enemyHp;
	float enemyMaxHp;
	int size;
	int flash;

public:
	Enemy(Texture* texture,Vector2f player_position, double direction, float speed,Vector2f position, int size);
	~Enemy();
	void Movement(float deltaTime);
	void Update(float deltaTime);
	void Draw(RenderTarget&target);
	void setEnemyHp(int hp);
	void setFlash();
	int getEnemyHp();
	int getCurrentSize();
	inline const Vector2f getPosition()const { return this->sprite.getPosition(); }
	inline FloatRect getGlobalBound()const { return this->sprite.getGlobalBounds(); }
	float vectorLength(Vector2f v) 
	{ 
		return sqrt(pow(v.x, 2) + pow(v.y, 2)); 
	} 
	Vector2f norm(Vector2f v, float length) 
	{ 
		return v / length; 
	}

};

