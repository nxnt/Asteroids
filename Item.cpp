#include "Item.h"

Item::Item(Texture* texture,Vector2f position,float time,int type)
{
	this->texture = texture;
	this->position = position;
	this->time = time;
	this->type = type;
	sprite.setPosition(this->position);
	sprite.setTexture(*this->texture);
	sprite.setOrigin(Vector2f(texture->getSize()) / 2.f);
	sprite.setScale(0.25,0.25);
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

