#pragma once
#include "../board.h"

namespace Patterns
{
	namespace StillLifes
	{
		/// <returns>4x4 still life pattern</returns>
		Board* Block()
		{
			uint8_t pattern[] = {
				0,0,0,0,
				0,1,1,0,
				0,1,1,0,
				0,0,0,0
			};

			return new Board(4, 4, pattern);
		}

		/// <returns>7x4 still life pattern</returns>
		Board* BiBlock()
		{
			uint8_t pattern[] = {
				0,0,0,0,0,0,0,
				0,1,1,0,1,1,0,
				0,1,1,0,1,1,0,
				0,0,0,0,0,0,0
			};

			return new Board(7, 4, pattern);
		}

		/// <returns>6x5 still life pattern</returns>
		Board* Hive()
		{
			uint8_t pattern[] = {
				0,0,0,0,0,0,
				0,0,1,1,0,0,
				0,1,0,0,1,0,
				0,0,1,1,0,0,
				0,0,0,0,0,0
			};

			return new Board(6, 5, pattern);
		}

		/// <returns>15x15 still life pattern</returns>
		Board* HoneyFarm()
		{
			uint8_t pattern[] = {
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
				0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
				0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,
				0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,
				0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
				0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,
				0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			};

			return new Board(15, 15, pattern);
		}
	}
}