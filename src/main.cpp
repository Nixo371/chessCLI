#include <iostream>
#include <string>

#include "game.hpp"

int main() {
	std::string starting_pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	Game game = Game(starting_pos);
	std::cout << game << std::endl;
}
