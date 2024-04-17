#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"

#define CELL_SIZE_X 8
#define CELL_SIZE_Y 8

using namespace std;

uint8_t pat[32] = {
	0,0,0,0,0,0,0,0,
	1,1,0,0,1,1,1,0,
	0,1,1,0,0,0,0,0,
	0,1,1,0,0,0,0,0
};

void RenderRound(sf::RenderWindow& window, Game& game)
{
	game.SimulateNewRound();
	size_t sizeX = game.GetSizeX();
	size_t sizeY = game.GetSizeY();

	window.clear(sf::Color(20,20,20,255));
	for(size_t i = 0 ; i < sizeY; i++)
		for (size_t j = 0; j < sizeX; j++)
			if (game.Get(j, i) == LIVE)
			{
				sf::RectangleShape rect(sf::Vector2f(CELL_SIZE_X, CELL_SIZE_Y));
				rect.setFillColor(sf::Color::White);
				rect.setPosition(sf::Vector2f(j * CELL_SIZE_X, i * CELL_SIZE_Y));
				window.draw(rect);
			}
	window.display();
}


int main()
{
	srand(time(NULL));
	Game game(200, 120);
	game.FillRandomly();
	//game.ReadBoardPattern(8, 4, pat);

	sf::RenderWindow window(sf::VideoMode(CELL_SIZE_X * game.GetSizeX(), CELL_SIZE_Y * game.GetSizeY()), "Game of Life");

	while(window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		RenderRound(window, game);

		sf::sleep(sf::seconds(1./11.));
	}

	return 0;

	game.ConsolePrint();
}
/**/