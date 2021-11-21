#pragma once
#include "Bullet.h"

class Player
{
private:
	Texture* texture;
	Texture* bulletTexture;
	CircleShape triangle;
	RectangleShape health_red;
	RectangleShape health_white;
	Vector2f position;
	Vector2f dir;
	Vector2f velocity;
	vector<Bullet> bullets;
	float maxSpeed;
	float acceleration;
	float mu;
	float rotateSpeed;
	float shootTimer;
	float shootTimerMax;
	int inv;
	int hp;
	int maxHp;
	int bulletLevel;

public:
	Player(Texture* texture, Vector2f position, Texture* bulletTexture);
	~Player();
	void Movement(float deltaTime);
	void Shoot();
	void Update(float deltaTime);
	void Draw(RenderTarget& target);
	void resetPlayer();

	int getInvincibility();
	void setInvincibility(int time);
	int getBulletLevel();
	void setBulletLevel(int bulletLevel);
	void setHp(int hp);
	int getHp();

	inline vector<Bullet>& getBullets() { return this->bullets; }
	inline const Vector2f& getPosition()const { return this->triangle.getPosition(); }
	inline FloatRect getGlobalBound()const { return this->triangle.getGlobalBounds(); }
	inline Vector2f getOrigin() { return this->triangle.getOrigin(); }
};

