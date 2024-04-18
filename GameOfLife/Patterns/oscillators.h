#pragma once
#include "../board.h"

namespace Patterns
{
	namespace Oscillators
	{
		/// <returns>3x3 oscillator pattern</returns>
		Board* Blinker()
		{
			uint8_t pattern[] = {
				0,1,0,
				0,1,0,
				0,1,0
			};

			return new Board(3, 3, pattern);
		}

		/// <returns>13x13 oscillator pattern</returns>
		Board* Star()
		{
			uint8_t pattern[]{
				0,0,0,0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,1,0,0,0,0,0,0,
				0,0,0,0,0,1,1,1,0,0,0,0,0,
				0,0,0,1,1,1,0,1,1,1,0,0,0,
				0,0,0,1,0,0,0,0,0,1,0,0,0,
				0,0,1,1,0,0,0,0,0,1,1,0,0,
				0,1,1,0,0,0,0,0,0,0,1,1,0,
				0,0,1,1,0,0,0,0,0,1,1,0,0,
				0,0,0,1,0,0,0,0,0,1,0,0,0,
				0,0,0,1,1,1,0,1,1,1,0,0,0,
				0,0,0,0,0,1,1,1,0,0,0,0,0,
				0,0,0,0,0,0,1,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,0,0,0,
			};

			return new Board(13, 13, pattern);
		}

		/// <returns>10x10 oscillator pattern</returns>
		Board* Cross()
		{
			uint8_t pattern[]{
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,1,1,1,1,0,0,0,
				0,0,0,1,0,0,1,0,0,0,
				0,1,1,1,0,0,1,1,1,0,
				0,1,0,0,0,0,0,0,1,0,
				0,1,0,0,0,0,0,0,1,0,
				0,1,1,1,0,0,1,1,1,0,
				0,0,0,1,0,0,1,0,0,0,
				0,0,0,1,1,1,1,0,0,0,
				0,0,0,0,0,0,0,0,0,0
			};

			return new Board(10, 10, pattern);
		}
	}
}