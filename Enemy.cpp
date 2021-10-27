#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2f player_position, double direction, float speed, Vector2f position, int size)
{
	this->texture = texture;
	this->speed = speed * 5 / size;
	this->position = position;
	sprite.setPosition(this->position);
	sprite.setTexture(*this->texture);
	this->enemyMaxHp = 25 * size;
	this->enemyHp = enemyMaxHp;
	this->direction = atan2f(player_position.y - position.y, player_position.x - position.x);
	this->offset_direction = direction * M_PI / 180;
	this->size = size;
	this->flash = 0;
	sprite.setScale(0.05 * size, 0.05 * size);
}

Enemy::~Enemy()
{

}

void Enemy::setEnemyHp(int hp)
{
	this->enemyHp += hp;
	if (this->enemyHp < 0)
	{
		this->enemyHp = 0;
	}
	if (this->enemyHp >= enemyMaxHp)
	{
		this->enemyHp = enemyMaxHp;
	}
}

int Enemy::getEnemyHp()
{
	return this->enemyHp;
}

void Enemy::setFlash()
{
	this->flash = 10;
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
	this->sprite.setColor(sf::Color(255, 255, 255, 255));
	if (this->flash > 0)
	{
		this->sprite.setColor(sf::Color(255, 0, 0, 255));
		this->flash--;
	}
}


void Enemy::Draw(RenderTarget& target)
{
	target.draw(sprite);
}
