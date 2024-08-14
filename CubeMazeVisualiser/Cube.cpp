#include "Cube.h"
#include <fstream>

using namespace std;
using namespace sf;
Cube::Cube()
{
	spriteSheet = new Texture();
}
Cube::Cube(RenderWindow* window)
{
	this->window = window;
	spriteSheet = new Texture();
	spriteSheet->loadFromFile("spritesheet.png");
	importMap("cube5.txt");
}
void Cube::importMap(string fileName)
{
	ifstream fileStream;
	fileStream.open(fileName);
	string currentLine;
	if (fileStream)
	{
		int y = 0;
		int z = -1;
		while (getline(fileStream, currentLine))
		{
			if (currentLine == "+")
			{
				z++;
				y = 0;
			}
			else
			{
				for (int i = 0; i < currentLine.size(); i++)
				{
					Block* block = new Block(Vector3f(i, y, z), currentLine[i], spriteSheet, *window);
					blocks[i][y][z] = block;
				}
				y++;
			}
		}
	}
}
Cube::~Cube()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < SIZE; k++)
			{
				delete blocks[i][j][k];
			}
		}
	}
	delete spriteSheet;
}
void Cube::draw()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			for (int k = 0; k < elevation + 1; k++)
			{
				blocks[i][j][k]->draw(*window);
			}
		}
	}
}

int Cube::getElevation()
{
	return elevation;
}
void Cube::setElevation(int elevation)
{
	this->elevation = elevation;
}