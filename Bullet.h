#pragma once
#include "Header.h"

class Bullet
{
private:
	Texture* texture;
	Sprite sprite;
	float speed;
	Vector2f dir;
	
public:

	Bullet(Texture* texture, float speed, Vector2f position, Vector2f dir, float rotate);
	void Movement();
	void Update();
	void Draw(RenderTarget& target);
	inline const Vector2f getPosition()const { return this->sprite.getPosition(); }
	inline FloatRect getGlobalBound()const { return this->sprite.getGlobalBounds(); }
};

