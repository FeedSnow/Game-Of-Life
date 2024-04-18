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

	void ReadBoardPattern(size_t sizeX, size_t sizeY, uint8_t* pattern)
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

	void PlacePattern(Board* pattern, size_t posX, size_t posY)
	{
		board->PlacePattern(pattern, posX, posY);
		delete pattern;
	}

	void FillRandomly()
	{
		size_t x = GetSizeX();
		size_t y = GetSizeY();
		for (size_t i = 0; i < y; i++)
			for (size_t j = 0; j < x; j++)
				board->Set(j, i, rand() % 2);
	}

	void SimulateNewRound()
	{
		size_t x = board->GetSizeX();
		size_t y = board->GetSizeY();
		Board *newBoard = new Board(x, y);
		for(size_t i = 0; i < y; i++)
			for (size_t j = 0; j < x; j++)
			{
				uint8_t newCellVal = DEAD;
				uint8_t neighboursValSum = board->GetNeighboursValSum(j, i);
				if (neighboursValSum == 3)
					newCellVal = LIVE;
				else if (neighboursValSum == 2)
					newCellVal = board->Get(j, i);

				newBoard->Set(j, i, newCellVal);
			}

		delete board;
		board = newBoard;
		newBoard = nullptr;
	}

	uint8_t Get(size_t cellX, size_t cellY)
	{
		return board->Get(cellX, cellY);
	}

	void Set(size_t cellX, size_t cellY, uint8_t value)
	{
		board->Set(cellX, cellY, value);
	}

	size_t GetSizeX() { return board->GetSizeX(); }
	size_t GetSizeY() { return board->GetSizeY(); }

	void ConsolePrint()
	{
		size_t x = GetSizeX();
		size_t y = GetSizeY();

		for (size_t i = 0; i < y; i++)
		{
			for (size_t j = 0; j < x; j++)
				cout << (int)board->Get(j, i);
			cout << endl;
		}
		cout << endl;
	}

private:
	Board* board;
};