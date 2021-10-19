#include "Player.h"

Player::Player(Texture* texture, Vector2f position,Texture* bulletTexture)
{
	this->position = position;
	this->texture = texture;
	this->bulletTexture = bulletTexture;
	this->triangle.setPosition(this->position.x, this->position.y);
	this->triangle.setRadius(80);
	this->triangle.setPointCount(3);
	this->triangle.setTexture(this->texture);
	this->triangle.setOrigin(this->triangle.getRadius(), this->triangle.getRadius());
	this->maxSpeed = 300.f;
	this->acceleration = 10;
	this->mu = 0.1f;
	this->rotateSpeed = 120;
	this->shootTimerMax = 25.f;
	this->shootTimer = this->shootTimerMax;
	this->inv = 0;
}

Player::~Player()
{

}

int Player::getInvincibility()  {
	return this->inv;
}

void Player::setInvincibility(int time) {
	this->inv = time;
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
	if (Keyboard::isKeyPressed(Keyboard::Space) && shootTimer >= shootTimerMax)
	{
		Vector2f bulletDir = normalize(rotateVector(Vector2f(0,-1), this->triangle.getRotation()));
		this->bullets.push_back(Bullet(this->bulletTexture, 30, triangle.getPosition(), bulletDir,triangle.getRotation()));
		shootTimer = 0;
	}
}

void Player::Update(float deltaTime)
{
	Movement(deltaTime);
	Shoot();
	if (shootTimer < shootTimerMax)
	{
		shootTimer++;
	}
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
	if (inv > 0)
	{
		inv--;
		this->triangle.setFillColor(sf::Color(255, 255, 255, 255)); // เซ็ตให้ปกติ
		if(inv % 30 > 15) this->triangle.setFillColor(sf::Color(255, 0, 0, 150)); // เซ็ตให้หายไป
	}
}

void Player::Draw(RenderTarget& target)
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(target);
	}
	target.draw(this->triangle);
}
