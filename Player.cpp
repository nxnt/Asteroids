#include "Player.h"

Player::Player(Texture* texture, Vector2f position)
{
	this->position = position;
	this->texture = texture;
	this->triangle.setPosition(this->position.x, this->position.y);
	this->triangle.setRadius(80);
	this->triangle.setPointCount(3);
	this->triangle.setTexture(this->texture);
	this->triangle.setOrigin(this->triangle.getRadius(), this->triangle.getRadius());
	this->maxSpeed = 300.f;
	this->acceleration = 10;
	this->mu = 0.1f;
	this->rotateSpeed = 120;
}

Player::~Player()
{

}

void Player::Movement(float deltaTime)
{
	this->dir = Vector2f();
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->triangle.rotate(-deltaTime * this->rotateSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->triangle.rotate(deltaTime * this->rotateSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->dir.y = -1;
		this->velocity += normalize(rotateVector(this->dir, this->triangle.getRotation())) * this->acceleration * deltaTime;
	}
	else
	{
		this->velocity -= (velocity * (1 - mu)) * deltaTime;
	}

	if (lenght(velocity) > maxSpeed * deltaTime)
	{
		velocity = normalize(velocity) * maxSpeed * deltaTime;
	}
	triangle.move(velocity);
}

void Player::Shoot()
{

}

void Player::Update(float deltaTime)
{
	Movement(deltaTime);
	if (this->triangle.getPosition().x < 0 + this->triangle.getRadius())
	{
		this->triangle.setPosition(Vector2f(0 + this->triangle.getRadius(), this->triangle.getPosition().y));
	}
	if (this->triangle.getPosition().x > 1920 - this->triangle.getRadius())
	{
		this->triangle.setPosition(Vector2f(1920 - this->triangle.getRadius(), this->triangle.getPosition().y));
	}
	if (this->triangle.getPosition().y < 0 + this->triangle.getRadius())
	{
		this->triangle.setPosition(Vector2f(this->triangle.getPosition().x, 0 + this->triangle.getRadius()));
	}
	if (this->triangle.getPosition().y > 1080 - this->triangle.getRadius())
	{
		this->triangle.setPosition(Vector2f(this->triangle.getPosition().x, 1080 - this->triangle.getRadius()));
	}

}

void Player::Draw(RenderTarget& target)
{
	target.draw(this->triangle);
}
