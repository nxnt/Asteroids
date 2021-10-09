#pragma once
#include "Player.h"
#include <vector>
class Game
{
private:
	
	RenderWindow* window;
	vector<Player> player;
	Texture playerTexture;
public:

	//Constructors / Destructors
	Game(RenderWindow* window);
	~Game();

	void Update(float deltaTime);
	void Draw();
};

