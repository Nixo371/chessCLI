#ifndef BOARD_H
# define BOARD_H

#include <vector>
#include <ostream>

#include "tile.hpp"

class Board {
	private:
		std::vector<std::vector<Tile>> tiles;
	public:
		Board(int ranks = 8, int files = 8);

		std::vector<std::vector<Tile>> get_board() const;
		void set_tile(int rank, int file, PieceType piece, PieceColor color);
};

std::ostream& operator<< (std::ostream& out, const Board& board);

#endif
