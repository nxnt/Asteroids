#include "Item.h"

Item::Item(Texture* texture,Vector2f position,float time, int type)
{
	this->texture = texture;
	this->position = position;
	this->time = time;
	this->type = type;
	sprite.setPosition(this->position);
	sprite.setTexture(*this->texture);
	sprite.setOrigin(Vector2f(texture->getSize()) / 2.f);
	if (this->type == 1 )
	{
		sprite.setScale(0.15,0.15);
	}
	else if (this->type == 2)
	{
		sprite.setScale(0.3,0.3);
	}
	else if (this->type == 3)
	{
		sprite.setScale(0.065, 0.065);
	}
}

Item::~Item()
{

}

void Item::Update()
{
	if (time > 0)
	{
		time--;
		this->sprite.setColor(sf::Color(255, 255, 255, 255)); // à«çµãËé»¡µÔ
		if (time % 30 > 15 && time < 300) this->sprite.setColor(sf::Color(255, 255,255, 150)); // à«çµãËéËÒÂä»

	}
}

int Item::getDelay()
{
	return this->time;
}

void Item::setDelay(int time)
{
	this->time = time;
}

void Item::Draw(RenderTarget& target)
{
	target.draw(sprite);
}

int Item::getType()
{
	return this->type = type;
}

