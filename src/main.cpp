#include <iostream>
#include <string>

#include "game.hpp"
#include "move.hpp"

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

	// bad game loop for now
	while (1) {
		std::string move_s;
		std::cout << "chessCLI> ";
		std::cin >> move_s;

		Move move = Move(move_s, game);
		game.play_move(move);
	
		std::cout << game << std::endl;
	}
}
