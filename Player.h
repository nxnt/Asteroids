#pragma once
#include "Bullet.h"

class Player
{
private:
	Texture* texture;
	Texture* bulletTexture;
	CircleShape triangle;
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

public:
	Player(Texture* texture, Vector2f position, Texture* bulletTexture);
	~Player();
	void Movement(float deltaTime);
	void Shoot();
	void Update(float deltaTime);
	void Draw(RenderTarget& target);

	int getInvincibility();
	void setInvincibility(int time);

	inline vector<Bullet>& getBullets() { return this->bullets; }
	inline const Vector2f& getPosition()const { return this->triangle.getPosition(); }
	inline FloatRect getGlobalBound()const { return this->triangle.getGlobalBounds(); }
};

