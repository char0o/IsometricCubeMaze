#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "BlockType.h"
#include "MathHelper.h"
using namespace sf;
class Block
{
public:
	Block();
	Block(Vector3f position, char type, Texture* texture,const RenderWindow& window);
	~Block();
	void draw(RenderWindow& window);
	void setPosition(Vector3f position, const RenderWindow& window);
	Vector3f getPosition();
	BlockType getType();
	void setType(BlockType type);
	BlockType getBlockTypeFromChar(char type);
	IntRect getTextureRect();
	const static int SIZE = 32;

private:
	Sprite* sprite;
	Vector3f position;
	BlockType type;
};

