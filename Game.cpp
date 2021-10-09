#include "Game.h"

Game::Game(RenderWindow* window)
{
	this->window = window;
	this->playerTexture.loadFromFile("Texture/Player/sprite.png");
	this->player.push_back(
		Player
		(
			&this->playerTexture,
			Vector2f(this->window->getSize().x/2, this->window->getSize().y / 2)
		)
	);
}

Game::~Game()
{

}

void Game::Update(float deltaTime)
{
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Update(deltaTime);
	}
}

void Game::Draw()
{
	this->window->clear();
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Draw(*this->window);
	}
	this->window->display();
}
