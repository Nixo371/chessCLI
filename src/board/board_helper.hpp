#ifndef BOARDHELPER_H
# define BOARDHELPER_H

#include <vector>

#include "../tile/tile.hpp"
#include "../piece/piece.hpp"
#include "../board/board.hpp"
#include "../game/game.hpp"

class BoardHelper {
	private:

	public:
		static std::vector<Tile> get_piece_mask(PieceType piece, Board board);
		static bool can_move_to(Game game, Tile tile, int rank, int file);
};

#endif
