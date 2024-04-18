#pragma once
#include "board.h"
#include "SFML/Graphics.hpp"

#define CELL_SIZE_X 8
#define CELL_SIZE_Y 8

class Game
{
public:
	Game(size_t sizeX, size_t sizeY);
	~Game();

	void ReadBoardPattern(size_t sizeX, size_t sizeY, uint8_t* pattern);
	void PlacePattern(Board* pattern, size_t posX, size_t posY);
	void FillRandomly();
	void UpdateCells();
	void ConsolePrint();

	void StartSimulation();
	void DisplayRound(sf::RenderWindow& window);

	void SetDarkTheme(bool on = true) { darkTheme = on; }
	bool IsDarkThemed() { return darkTheme; }

	void SetFrameDuration(sf::Time duration);
	sf::Time GetFrameDuration() { return frameTime; }

	uint8_t Get(size_t cellX, size_t cellY) { return board->Get(cellX, cellY); }
	void Set(size_t cellX, size_t cellY, uint8_t value) { board->Set(cellX, cellY, value); }

	size_t GetSizeX() { return board->GetSizeX(); }
	size_t GetSizeY() { return board->GetSizeY(); }

private:
	Board* board;
	sf::Time frameTime = sf::seconds(0.1);
	bool darkTheme = true;
};