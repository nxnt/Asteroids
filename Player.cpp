#include "Player.h"

Player::Player(Texture* texture, Vector2f position)
{
	this->position = position;
	this->texture = texture;
	this->triangle.setPosition(this->position.x, this->position.y);
	this->triangle.setRadius(80);
	this->triangle.setPointCount(3);
	this->triangle.setTexture(this->texture);
	this->moveSpeed = 100.f;
}

Player::~Player()
{

}

void Player::Movement(float deltaTime)
{
	this->dir.x = this->moveSpeed * sin((this->triangle.getRotation() * M_PI) / 180);
	this->dir.y = this->moveSpeed * -cos((this->triangle.getRotation() * M_PI) / 180);
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->triangle.rotate(-deltaTime * this->moveSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->triangle.rotate(deltaTime * this->moveSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->triangle.move(this->dir.x * deltaTime,this->dir.y * deltaTime);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->triangle.move(this->dir.x * -deltaTime,this->dir.y * -deltaTime);
	}

}

void Player::Shoot()
{

}

void Player::Update(float deltaTime)
{
	this->triangle.setOrigin(Vector2f(this->triangle.getLocalBounds().width / 2.f, this->triangle.getLocalBounds().height / 2.f));
	Movement(deltaTime);
}

void Player::Draw(RenderTarget& target)
{
	target.draw(this->triangle);
}
