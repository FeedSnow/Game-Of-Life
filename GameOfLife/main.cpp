#include <iostream>
#include "game.h"

using namespace std;

uint8_t pat[32] = {
	0,0,0,0,0,0,0,0,
	1,1,0,0,1,1,1,0,
	0,1,1,0,0,0,0,0,
	0,1,1,0,0,0,0,0
};


int main()
{
	Game game(8, 4);
	game.ReadBoardPattern(8, 4, pat);
	game.ConsolePrint();
}