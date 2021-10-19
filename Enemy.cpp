#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2f player_position, double direction, float speed, Vector2f position, int size)
{
	this->texture = texture;
	this->speed = speed * 5 / size;
	this->position = position;
	sprite.setPosition(this->position);
	sprite.setTexture(*this->texture);

	this->direction = atan2f(player_position.y - position.y, player_position.x - position.x);
	this->offset_direction = direction * M_PI / 180;
	this->size = size;

	sprite.setScale(0.5 * size, 0.5 * size);
}

Enemy::~Enemy()
{

}

int Enemy::getCurrentSize() {

	return this->size;
}

void Enemy::Movement(float deltaTime)
{
	sprite.move(cos(this->direction + this->offset_direction) * speed * deltaTime, sin(this->direction + this->offset_direction) * speed * deltaTime);
}

void Enemy::Update(float deltaTime)
{
	Movement(deltaTime);
}


void Enemy::Draw(RenderTarget& target)
{
	target.draw(sprite);
}
