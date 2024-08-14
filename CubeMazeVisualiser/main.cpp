#include "SFML/Graphics.hpp"
#include "Cube.h"
using namespace sf;
void pollEvent(RenderWindow* window, Cube& cube);
void main()
{
	sf::RenderWindow* window = new RenderWindow(sf::VideoMode(800, 600), "Cube Maze Visualiser");
	View view = window->getView();
	view.zoom(0.5f);
	window->setFramerateLimit(60);

	Cube cube(window);
	while (window->isOpen())
	{
		pollEvent(window, cube);
		window->setView(view);
		window->clear();

		cube.draw();

		window->display();
	}
	delete window;
}

void pollEvent(RenderWindow* window, Cube& cube)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Num1)
			{
				cube.setElevation(0);
			}
			if (event.key.code == sf::Keyboard::Num2)
			{
				cube.setElevation(1);
			}
			if (event.key.code == sf::Keyboard::Num3)
			{
				cube.setElevation(2);
			}
			if (event.key.code == sf::Keyboard::Num4)
			{
				cube.setElevation(3);
			}
			if (event.key.code == sf::Keyboard::Num5)
			{
				cube.setElevation(4);
			}
		}
	}
}