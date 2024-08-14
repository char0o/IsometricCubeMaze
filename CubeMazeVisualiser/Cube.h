#pragma once
#include "Block.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace sf;
using namespace std;
class Cube
{
public:
	Cube();
	Cube(RenderWindow* window);
	~Cube();
	void draw();
	constexpr static int SIZE = 5;
	Block* blocks[SIZE][SIZE][SIZE];

	int getElevation();
	void setElevation(int elevation);

	void importMap(string fileName);
private:
	Texture* spriteSheet;
	RenderWindow* window;
	int elevation = 0;
};

