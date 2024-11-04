#include <iostream>
#include <string>

#include "game.hpp"

int main(int argc, char *argv[]) {
	std::string starting_pos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
	
	if (argc == 2) {
		starting_pos = argv[1];
	}
	else if (argc > 2) {
		std::cout << "WRONG USAGE: \'./chessCLI [FEN]\'" << std::endl;
	}

	Game game = Game(starting_pos);
	std::cout << game << std::endl;
}
