#pragma once

#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "Block.h"
using namespace sf;


Vector2f linearToIsometric(const Vector3f& point, const RenderWindow& window);
