#ifndef MOVE_H
# define MOVE_H

#include "move_type.hpp"
#include "../tile/tile.hpp"
#include "../game/game.hpp"

class Move {
	private:
		Tile from;
		Tile to;
		MoveType move_type;
		PieceType piece;
		PieceType promotion_piece;
	public:
		Move(std::string move, Game game);
};

#endif
