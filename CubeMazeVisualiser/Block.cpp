#include "Block.h"

Block::Block()
{
	sprite = new Sprite();
	position = Vector3f(0, 0, 0);
	type = BlockType::Ground;
}
Block::Block(Vector3f position, char type, Texture* texture, const RenderWindow& window)
{
	sprite = new Sprite(*texture);
	setPosition(position, window);
	if (isdigit(type))
	{
		type = ' ';
	}
	this->setType(getBlockTypeFromChar(type));
}
Block::~Block()
{
	delete sprite;
}
BlockType Block::getBlockTypeFromChar(char type)
{
	switch (type)
	{
	case 'U':
		return BlockType::LadderUp;
	case 'D':
		return  BlockType::LadderDown;
	case '*':
		return BlockType::Wall;
	case ' ':
		return BlockType::Ground;
	}
	return BlockType::Ground;
}
IntRect Block::getTextureRect()
{
	switch (type)
	{
	case BlockType::LadderUp:
		return IntRect(32, 0, SIZE, SIZE);
	case BlockType::LadderDown:
		return IntRect(64, 0, SIZE, SIZE);
	case BlockType::Wall:
		return IntRect(0, 0, SIZE, SIZE);
	case BlockType::Ground:
		return IntRect(96, 0, SIZE, SIZE);
	}
	return IntRect(0, 0, SIZE, SIZE);
}
void Block::draw(RenderWindow& window)
{
	window.draw(*sprite);
}
Vector3f Block::getPosition()
{
	return position;
}
void Block::setPosition(Vector3f position, const RenderWindow& window)
{
	this->position = position;
	Vector2f isometricPosition = linearToIsometric(position, window);
	sprite->setPosition(isometricPosition + Vector2f(0, window.getSize().y / 2.0));
}
BlockType Block::getType()
{
	return type;
}
void Block::setType(BlockType type)
{
	this->type = type;
	this->sprite->setTextureRect(getTextureRect());
}
