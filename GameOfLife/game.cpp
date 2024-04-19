#include "game.h"
#include <iostream>

Game::Game(size_t sizeX, size_t sizeY)
{
	board = new Board(sizeX, sizeY);
}

Game::~Game()
{
	delete board;
}

void Game::InitBoardFromPattern(size_t sizeX, size_t sizeY, uint8_t* pattern)
{
	if (!pattern)
	{
		cerr << "Array does not exist." << endl;
		exit(1);
	}

	if (board)
		delete board;
	board = new Board(sizeX, sizeY, pattern);
	if (!board)
	{
		cerr << "Board initialization error." << endl;
		exit(2);
	}

}

void Game::PlacePattern(Board* pattern, size_t posX, size_t posY)
{
	board->PlacePattern(pattern, posX, posY);
	delete pattern;
}

void Game::FillRandomly()
{
	size_t x = GetSizeX();
	size_t y = GetSizeY();
	for (size_t i = 0; i < y; i++)
		for (size_t j = 0; j < x; j++)
			board->Set(j, i, rand() % 2);
}

void Game::UpdateCells()
{
	size_t x = board->GetSizeX();
	size_t y = board->GetSizeY();
	Board* newBoard = new Board(x, y);
	for (size_t i = 0; i < y; i++)
		for (size_t j = 0; j < x; j++)
		{
			uint8_t newCellVal = 0;
			uint8_t neighboursValSum = board->GetNeighboursValSum(j, i);
			if (neighboursValSum == 3)
				newCellVal = 1;
			else if (neighboursValSum == 2)
				newCellVal = board->Get(j, i);

			newBoard->Set(j, i, newCellVal);
		}

	delete board;
	board = newBoard;
	newBoard = nullptr;
}

void Game::SetFrameDuration(sf::Time duration)
{
	frameTime = duration;
}

void Game::DisplayRound(sf::RenderWindow& window)
{
	size_t sizeX = GetSizeX();
	size_t sizeY = GetSizeY();
	sf::Color deadColor = (darkTheme ? sf::Color(20, 20, 20, 255) : sf::Color::White);
	sf::Color liveColor = (darkTheme ? sf::Color::White : sf::Color::Black);

	window.clear(deadColor);
	for (size_t i = 0; i < sizeY; i++)
		for (size_t j = 0; j < sizeX; j++)
			if (Get(j, i) == 1)
			{
				sf::RectangleShape rect(sf::Vector2f(CELL_SIZE_X, CELL_SIZE_Y));
				rect.setFillColor(liveColor);
				rect.setPosition(sf::Vector2f(j * CELL_SIZE_X, i * CELL_SIZE_Y));
				window.draw(rect);
			}
	window.display();
}

void Game::StartSimulation()
{
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE_X * GetSizeX(), CELL_SIZE_Y * GetSizeY()), "Game of Life");

	while (window.isOpen())
	{
		DisplayRound(window);

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::sleep(frameTime);
		UpdateCells();
	}
}