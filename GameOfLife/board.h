#pragma once
#include <stdint.h>
#include <iostream>

using namespace std;

class Board
{
public:
	Board(size_t x, size_t y)
	{
		sizeX = x;
		sizeY = y;
		board = new uint8_t * [sizeX];
		if (!board)
		{
			cerr << "Board initialization error." << endl;
			exit(1);
		}

		for (size_t i = 0; i < sizeX; i++)
		{
			board[i] = new uint8_t[sizeY];
			for (size_t j = 0; j < sizeY; j++)
				board[i][j] = DEAD;
		}
	}

	~Board()
	{
		if (board)
		{
			for (size_t i = 0; i < sizeX; i++)
				if (board[i])
				{
					delete board[i];
					board[i] = nullptr;
				}
			delete board;
			board = nullptr;
		}
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

	uint8_t Get(size_t x, size_t y)
	{
		if (!IsInBounds(x, y))
		{
			return 0;
		}

		return board[x][y];
	}

	bool Exists()
	{
		if (!board)
			return false;
		return true;
	}

	void Set(size_t x, size_t y, uint8_t value)
	{
		if (!IsInBounds(x, y))
		{
			cerr << "Index out of range." << endl;
			return;
		}

		if (!IsAcceptableCellValue(value))
		{
			cerr << "Unacceptable cell value." << endl;
			return;
		}

		board[x][y] = value;
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
	uint8_t** board = nullptr;
	size_t sizeX = 0;
	size_t sizeY = 0;
};

enum CellType
{
	DEAD = 0,
	LIVE,
	ERROR
};