#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

using namespace sf;
using namespace std;

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

