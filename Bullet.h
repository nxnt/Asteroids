#pragma once
#include "NontHeader.h"

class Bullet
{
private:
	Texture* texture;
	Sprite sprite;
	float speed;

public:

	Bullet(Texture* texture, float speed, Vector2f position, Vector2f dir);
	void Movement();
	void Update();
	void Draw(RenderTarget& target);
};

