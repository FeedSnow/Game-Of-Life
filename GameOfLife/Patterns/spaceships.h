#pragma once
#include "../board.h"

namespace Patterns
{
	namespace Spaceships
	{
		/// <returns>5x5 spaceship pattern</returns>
		Board* Glider()
		{
			uint8_t pattern[]{
				0,0,0,0,0,
				0,0,1,0,0,
				0,0,0,1,0,
				0,1,1,1,0,
				0,0,0,0,0
			};

			return new Board(5, 5, pattern);
		}

		/// <returns>7x6 spaceship pattern</returns>
		Board* LWSS()
		{
			uint8_t pattern[]{
				0,0,0,0,0,0,0,
				0,1,0,0,1,0,0,
				0,0,0,0,0,1,0,
				0,1,0,0,0,1,0,
				0,0,1,1,1,1,0,
				0,0,0,0,0,0,0
			};

			return new Board(7, 6, pattern);
		}

		/// <returns>8x7 spaceship pattern</returns>
		Board* MWSS()
		{
			uint8_t pattern[]{
				0,0,0,0,0,0,0,0,
				0,0,0,1,0,0,0,0,
				0,1,0,0,0,1,0,0,
				0,0,0,0,0,0,1,0,
				0,1,0,0,0,0,1,0,
				0,0,1,1,1,1,1,0,
				0,0,0,0,0,0,0,0
			};

			return new Board(8, 7, pattern);
		}

		/// <returns>9x7 spaceship pattern</returns>
		Board* HWSS()
		{
			uint8_t pattern[]{
				0,0,0,0,0,0,0,0,0,
				0,0,0,1,1,0,0,0,0,
				0,1,0,0,0,0,1,0,0,
				0,0,0,0,0,0,0,1,0,
				0,1,0,0,0,0,0,1,0,
				0,0,1,1,1,1,1,1,0,
				0,0,0,0,0,0,0,0,0
			};

			return new Board(9, 7, pattern);
		}
	}
}