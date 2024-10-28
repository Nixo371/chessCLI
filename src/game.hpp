#ifndef GAME_H
# define GAME_H

#include <vector>
#include <iostream>

#include "board.hpp"
#include "gamemetadata.hpp"

class Game {
	private:
		Board board;
		GameMetadata metadata;
	public:
		Game();
		Game(std::string fen);

		Board get_board() const;
};

std::ostream& operator<< (std::ostream& out, const Game& game);

#endif
