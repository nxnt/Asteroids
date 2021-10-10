#pragma once
#include "Player.h"

class Game
{
private:
	
	RenderWindow* window;
	vector<Player> player;
	Texture playerTexture;
	Texture bulletTexture;
public:

	//Constructors / Destructors
	Game(RenderWindow* window);
	~Game();

	void Update(float deltaTime);
	void Draw();
};

