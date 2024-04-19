# Game of Life

The project is based on [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life). It was made with C++ and SFML.

## How to run (Visual Studio)

1. Download [SFML-2.6.1](https://www.sfml-dev.org/download/sfml/2.6.1/)
2. In project properties:
   - Put `<sfml-install-path>/include` to C/C++ > General > Additional Include Directiories
   - Put `<sfml-install-path>/lib` to Linker > General > Additional Library Directories
3. If You don't use my `.vcxproj` file:
   Add libraries to Linker > Input > Additional Dependencies:
   - For **Debug**:
     - `sfml-graphics-d.lib`
     - `sfml-window-d.lib`
     - `sfml-system-d.lib`
   - For **Release**:
     - `sfml-graphics.lib`
     - `sfml-window.lib`
     - `sfml-system.lib`
4. Add DLLs to Your application folder:
   - If built with **Debug** configuration:
     - `sfml-graphics-d-2.dll`
     - `sfml-system-d-2.dll`
     - `sfml-window-d-2.dll`
   - If built with **Release** configuration:
     - `sfml-graphics-2.dll`
     - `sfml-system-2.dll`
     - `sfml-window-2.dll`
    
## How to use

You can create empty `Game` object or init it with any existing `Board` object. Then You can fill it randomly using `game.FillRandomly()` or put any existing pattern using `game.PlacePattern()`. You can also change any cell independently using `game.Set()`.
For placing patterns on board You can use built-in functions from `Patterns` directory (probably I will add more of them in future) or by creating Your own boards. Built-in patterns are described with their sizes. To make your patterns not override other elements with their background, put line `#define IGNORE_DEAD` to `board.h` or `board.cpp`.

You can change theme with `game.SetDarkTheme()`. Basicly, it's just choice of white-on-dark or dark-on-white cells.

You can adjust simulation speed by changing frame time with `game.SetFrameDuration()`.

To run simulation use `game.StartSimulation()`.
