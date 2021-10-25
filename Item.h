#pragma once
#include "Header.h"
class Item

{
private:
	Texture* texture;
	Vector2f position;
	Sprite sprite;
	int time;
	int type;

public:
	Item(Texture* texture, Vector2f position, float time,int type);
	~Item();
	void Update();
	int getDelay();
	void setDelay(int time);
	void Draw(RenderTarget& target);
	inline const Vector2f getPosition()const { return this->sprite.getPosition(); }
	inline FloatRect getGlobalBound()const { return this->sprite.getGlobalBounds(); }
	int getType();
};

