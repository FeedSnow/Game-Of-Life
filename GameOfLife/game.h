#pragma once
#include "board.h"

class Game
{
public:
	Game(size_t sizeX, size_t sizeY);
	~Game();

	void ReadBoardPattern(size_t sizeX, size_t sizeY, uint8_t* pattern);
	void PlacePattern(Board* pattern, size_t posX, size_t posY);
	void FillRandomly();
	void SimulateNewRound();
	void ConsolePrint();

	uint8_t Get(size_t cellX, size_t cellY) { return board->Get(cellX, cellY); }
	void Set(size_t cellX, size_t cellY, uint8_t value) { board->Set(cellX, cellY, value); }

	size_t GetSizeX() { return board->GetSizeX(); }
	size_t GetSizeY() { return board->GetSizeY(); }

private:
	Board* board;
};