#pragma once
#include "Header.h"

class Enemy
{
private:
	Texture* texture;
	Vector2f direction;
	float speed;
	Vector2f position;
	Sprite sprite;

public:
	Enemy(Texture* texture,Vector2f direction,float speed,Vector2f position);
	~Enemy();
	void Movement(float deltaTime);
	void Update(float deltaTime);
	void Draw(RenderTarget&target);
	inline const Vector2f& getPosition()const { return this->sprite.getPosition(); }
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

