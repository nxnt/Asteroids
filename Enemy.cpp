#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2f direction, float speed, Vector2f position)
{
	this->texture = texture;
	this->direction = direction;
	this->speed = speed;
	this->position = position;
	sprite.setPosition(this->position);
	sprite.setTexture(*this->texture);
	
}

Enemy::~Enemy()
{

}

void Enemy::Movement(float deltaTime)
{
	float a = vectorLength(direction);
	Vector2f b = norm(direction, a); // b = direction
	sprite.move(b.x * speed * deltaTime, b.y * speed * deltaTime);
}

void Enemy::Update(float deltaTime)
{
	Movement(deltaTime);
}


void Enemy::Draw(RenderTarget& target)
{
	target.draw(sprite);
}
