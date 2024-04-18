#pragma once
#include <stdint.h>
#include <iostream>

using namespace std;

enum CellType
{
	DEAD = 0,
	LIVE,
	ERROR
};

class Board
{
public:
	Board(size_t x, size_t y)
	{
		sizeX = x;
		sizeY = y;
		board = new uint8_t [sizeX * sizeY];
		if (!board)
		{
			cerr << "Board initialization error." << endl;
			exit(1);
		}

		for (size_t i = 0; i < sizeX * sizeY; i++)
			board[i] = DEAD;
	}

	Board(size_t x, size_t y, uint8_t* patternArray)
	{
		if (!patternArray)
		{
			cerr << "Wrong argument." << endl;
			exit(3);
		}

		sizeX = x;
		sizeY = y;
		board = new uint8_t [sizeX * sizeY];
		if (!board)
		{
			cerr << "Board initialization error." << endl;
			exit(1);
		}

		for (size_t i = 0; i < sizeX * sizeY; i++)
			board[i] = patternArray[i];
	}

	~Board()
	{
		if (board)
		{
			delete[] board;
			board = nullptr;
		}
	}

	void PlacePattern(Board* pattern, size_t posX, size_t posY)
	{
		if (!IsInBounds(posX + pattern->GetSizeX() - 1, posY + pattern->GetSizeY() - 1))
		{
			cerr << "Pattern too large for chosen place." << endl;
			return;
		}

		size_t patSizeX = pattern->GetSizeX();
		size_t patSizeY = pattern->GetSizeY();

		for (size_t i = 0; i < patSizeY; i++)
			for (size_t j = 0; j < patSizeX; j++)
				board[(i + posY) * sizeX + (j + posX)] = pattern->Get(j, i);
	}

	bool IsInBounds(size_t x, size_t y)
	{
		return (x < sizeX && y < sizeY);
	}

	bool IsAcceptableCellValue(uint8_t value)
	{
		if (value < ERROR)
			return true;
		return false;
	}

	uint8_t Get(size_t cellX, size_t cellY)
	{
		if (!IsInBounds(cellX, cellY))
		{
			return 0;
		}

		return board[cellY * sizeX + cellX];
	}

	bool Exists()
	{
		if (!board)
			return false;
		return true;
	}

	void Set(size_t cellX, size_t cellY, uint8_t value)
	{
		if (!IsInBounds(cellX, cellY))
		{
			cerr << "Index out of range." << endl;
			return;
		}

		if (!IsAcceptableCellValue(value))
		{
			cerr << "Unacceptable cell value." << endl;
			return;
		}

		board[cellY * sizeX + cellX] = value;
	}

	size_t GetSizeX()
	{
		return sizeX;
	}

	size_t GetSizeY()
	{
		return sizeY;
	}

	uint8_t GetNeighboursValSum(size_t cellX, size_t cellY)
	{
		if (!Exists())
		{
			cerr << "Board has not been initialized." << endl;
			exit(1);
		}
		if (!IsInBounds(cellX, cellY))
		{
			cerr << "Index out of range." << endl;
			exit(2);
		}

		uint8_t sum = 0;
		sum += Get(cellX - 1,	cellY - 1);
		sum += Get(cellX - 1,	cellY);
		sum += Get(cellX - 1,	cellY + 1);
		sum += Get(cellX,		cellY + 1);
		sum += Get(cellX + 1,	cellY + 1);
		sum += Get(cellX + 1,	cellY);
		sum += Get(cellX + 1,	cellY - 1);
		sum += Get(cellX,		cellY - 1);

		return sum;
	}

private:
	uint8_t* board = nullptr;
	size_t sizeX = 0;
	size_t sizeY = 0;
};