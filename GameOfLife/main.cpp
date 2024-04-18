#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "Patterns/oscillators.h"
#include "Patterns/spaceships.h"
#include "Patterns/still_lifes.h"

using namespace std;

namespace ss = Patterns::Spaceships;
namespace sl = Patterns::StillLifes;
namespace osc = Patterns::Oscillators;

int main()
{
	srand(time(NULL));
	Game game(200, 120);
	game.PlacePattern(osc::Star(), 0, 0);
	game.PlacePattern(osc::Cross(), 15, 0);
	game.PlacePattern(ss::Glider(), 0, 20);
	game.PlacePattern(ss::LWSS(), 0, 40);
	game.PlacePattern(ss::MWSS(), 0, 60);
	game.PlacePattern(ss::HWSS(), 0, 80);

	game.StartSimulation();
	

	return 0;
}
/**/