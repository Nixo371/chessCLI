#ifndef BOARDHELPER_H
# define BOARDHELPER_H

# include <vector>

# include "tile.hpp"
# include "piece.hpp"
# include "board.hpp"
# include "game.hpp"

class BoardHelper {
	private:
	public:
		static std::vector<Tile> get_piece_mask(PieceType piece, Board board);
		static bool can_move_to(Game game, Tile tile, int rank, int file);
};

#endif
