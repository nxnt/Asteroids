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
	this->health_white.setPosition(28,48);
	this->health_white.setFillColor(Color(255,255,255,255));
	this->health_white.setSize(Vector2f(504.f, 34.f));
	this->health_red.setPosition(30,50);
	this->health_red.setFillColor(Color(255,0,0,255));
	this->hp = 100;
	this->maxHp = 100;
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

void Player::setHp(int hp)
{
	this->hp += hp;
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
		/*Vector2f bulletDir = normalize(rotateVector(Vector2f(0, -1), this->triangle.getRotation()));
		this->bullets.push_back
		(
			Bullet
			(
				this->bulletTexture, 
				30, 
				triangle.getPosition(), 
				bulletDir,
				triangle.getRotation()
			)
		);*/
		Vector2f bulletDir = normalize(rotateVector(Vector2f(0, -1), this->triangle.getRotation() + 3));
		this->bullets.push_back
		(
			Bullet
			(
				this->bulletTexture,
				30,
				triangle.getPosition(),
				bulletDir,
				triangle.getRotation()
			)
		);
		bulletDir = normalize(rotateVector(Vector2f(0, -1), this->triangle.getRotation() - 3));
		this->bullets.push_back
		(
			Bullet
			(
				this->bulletTexture,
				30,
				triangle.getPosition(),
				bulletDir,
				triangle.getRotation()
			)
		);

		
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
		this->triangle.setFillColor(sf::Color(255, 255, 255, 255)); // à«çµãËé»¡µÔ
		if(inv % 30 > 15) this->triangle.setFillColor(sf::Color(255, 0, 0, 150)); // à«çµãËéËÒÂä»
	}
	float player_hp = ((float)this->hp / (float)this->maxHp) * 500.f;
	if (player_hp > 500.f)
	{
		player_hp = 500.f;
	}
	else if (player_hp < 0)
	{
		player_hp = 0.f;
	}
	this->health_red.setSize(Vector2f(player_hp, 30.f));
}

void Player::Draw(RenderTarget& target)
{
	for (size_t i = 0; i < bullets.size(); i++)
	{
		bullets[i].Draw(target);
	}
	target.draw(this->triangle);
	target.draw(this->health_white);
	target.draw(this->health_red);
}
