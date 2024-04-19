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

	game.FillRandomly();

	game.StartSimulation();
	

	return 0;
}
/**/