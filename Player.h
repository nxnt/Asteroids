#pragma once
#include "Bullet.h"

class Player
{
private:
	Texture* texture;
	CircleShape triangle;
	Vector2f position;
	Vector2f dir;
	float moveSpeed;
public:
	Player(Texture* texture,Vector2f position);
	~Player();
	void Movement(float deltaTime);
	void Shoot();
	void Update(float deltaTime);
	void Draw(RenderTarget &target);

};
