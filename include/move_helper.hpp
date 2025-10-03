#ifndef MOVE_HELPER_H
# define MOVE_HELPER_H

# include <vector>

# include "game.hpp"
# include "tile.hpp"

class MoveHelper {
	private:

	public:
		static std::vector<Tile> pawn_moves(Game game, Tile from);
		static std::vector<Tile> knight_moves(Game game, Tile from);
		static std::vector<Tile> bishop_moves(Game game, Tile from);
		static std::vector<Tile> rook_moves(Game game, Tile from);
		static std::vector<Tile> queen_moves(Game game, Tile from);
		static std::vector<Tile> king_moves(Game game, Tile from);
};

#endif
