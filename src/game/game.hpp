#ifndef GAME_H
# define GAME_H

#include <vector>
#include <iostream>

#include "../board/board.hpp"
#include "gamemetadata.hpp"

class Game {
	private:
		Board board;
		GameMetadata metadata;
	public:
		Game();
		Game(std::string fen);

		Board get_board() const;
		int get_turn();
};

std::ostream& operator<< (std::ostream& out, const Game& game);

#endif
