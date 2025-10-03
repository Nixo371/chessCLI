#ifndef GAME_H
# define GAME_H

# include <iostream>

# include "board.hpp"
# include "move.hpp"
# include "gamemetadata.hpp"

class Game {
	private:
		Board board;
		GameMetadata metadata;
	public:
		Game();
		Game(std::string fen);
		
		bool play_move(Move move);
		
		Board get_board() const;
		int get_turn();
		Tile get_en_passant();
};

std::ostream& operator<< (std::ostream& out, const Game& game);

#endif
