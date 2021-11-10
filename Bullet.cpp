#include "Bullet.h"

Bullet::Bullet(Texture* texture, float speed, Vector2f position, Vector2f dir, float rotate)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);

	Vector2f new_dir = normalize(rotateVector(Vector2f(0, 0), rotate));

	this->sprite.setPosition(position);
	this->dir = dir;
	this->speed = speed;
	this->sprite.setRotation(rotate);
	this->sprite.setOrigin(Vector2f (texture->getSize()) / 2.f);
}

void Bullet::Movement()
{
	this->sprite.move(this->speed * this->dir.x, this->speed * this->dir.y);
}

void Bullet::Update()
{
	Movement();
}

void Bullet::Draw(RenderTarget& target)
{
	target.draw(this->sprite);
}
