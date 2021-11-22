#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <time.h>

using namespace sf;
using namespace std;

// return random number in range [start, stop]
inline int randrange(int start, int stop)
{
    return rand() % (stop - start + 1) + start;
}

inline float lenght(Vector2f vec)
{
    return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

inline Vector2f normalize(Vector2f vec)
{
    float len = sqrtf(vec.x * vec.x + vec.y * vec.y);
    if (len != 0)
        return vec / len;
    return vec;
}


inline Vector2f rotateVector(Vector2f dir, float angle)
{
    if (dir == Vector2f(0, 0))
        return Vector2f(0, 0);
    float nx = dir.x * cos((angle) * M_PI / 180) - dir.y * sin((angle) * M_PI / 180);
    float ny = dir.x * sin((angle) * M_PI / 180) + dir.y * cos((angle) * M_PI / 180);
    return Vector2f(nx, ny);
}