#pragma once
#include <stdint.h>

using namespace std;

class Board
{
public:
	Board(size_t x, size_t y);
	Board(size_t x, size_t y, uint8_t* patternArray);
	~Board();

	void PlacePattern(Board* pattern, size_t posX, size_t posY);

	uint8_t GetNeighboursValSum(size_t cellX, size_t cellY);

	uint8_t Get(size_t cellX, size_t cellY);
	void Set(size_t cellX, size_t cellY, uint8_t value);

	size_t GetSizeX() { return sizeX; }
	size_t GetSizeY() { return sizeY; }

private:
	uint8_t* board = nullptr;
	size_t sizeX = 0;
	size_t sizeY = 0;

	bool IsInBounds(size_t x, size_t y);
	bool IsAcceptableCellValue(uint8_t value);
};