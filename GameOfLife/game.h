#pragma once
#include "board.h"

class Game
{
public:
	Game(size_t sizeX, size_t sizeY)
	{
		board = new Board(sizeX, sizeY);
	}

	~Game()
	{
		delete board;
	}

	void SimulateNewRound()
	{
		
	}
private:
	Board* board;
};