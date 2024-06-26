#include "board.h"
#include <iostream>

Board::Board(size_t x, size_t y)
{
	sizeX = x;
	sizeY = y;
	board = new uint8_t[sizeX * sizeY];
	if (!board)
	{
		cerr << "Board initialization error." << endl;
		exit(2);
	}

	for (size_t i = 0; i < sizeX * sizeY; i++)
		board[i] = 0;
}

Board::Board(size_t x, size_t y, uint8_t* patternArray)
{
	if (!patternArray)
	{
		cerr << "Array does not exist." << endl;
		exit(1);
	}

	sizeX = x;
	sizeY = y;
	board = new uint8_t[sizeX * sizeY];
	if (!board)
	{
		cerr << "Board initialization error." << endl;
		exit(2);
	}

	for (size_t i = 0; i < sizeX * sizeY; i++)
		board[i] = patternArray[i];
}

Board::~Board()
{
	if (board)
	{
		delete[] board;
		board = nullptr;
	}
}

void Board::PlacePattern(Board* pattern, size_t posX, size_t posY)
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
		{
			uint8_t cell = pattern->Get(j, i);
#ifdef IGNORE_DEAD
			if(cell == LIVE)
#endif
				board[(i + posY) * sizeX + (j + posX)] = cell;
		}
}

uint8_t Board::GetNeighboursValSum(size_t cellX, size_t cellY)
{
	if (!board)
	{
		cerr << "Board does not exist." << endl;
		exit(1);
	}
	if (!IsInBounds(cellX, cellY))
	{
		cerr << "Index out of range." << endl;
		exit(2);
	}

	uint8_t sum = 0;
	sum += Get(cellX - 1, cellY - 1);
	sum += Get(cellX - 1, cellY);
	sum += Get(cellX - 1, cellY + 1);
	sum += Get(cellX, cellY + 1);
	sum += Get(cellX + 1, cellY + 1);
	sum += Get(cellX + 1, cellY);
	sum += Get(cellX + 1, cellY - 1);
	sum += Get(cellX, cellY - 1);

	return sum;
}

uint8_t Board::Get(size_t cellX, size_t cellY)
{
	if (!IsInBounds(cellX, cellY))
	{
		return 0;
	}

	return board[cellY * sizeX + cellX];
}

void Board::Set(size_t cellX, size_t cellY, uint8_t value)
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

bool Board::IsInBounds(size_t x, size_t y)
{
	return (x < sizeX && y < sizeY);
}

bool Board::IsAcceptableCellValue(uint8_t value)
{
	if (value < 2)
		return true;
	return false;
}