#ifndef MOVE_H
# define MOVE_H

#include "move_type.hpp"
#include "../tile/tile.hpp"

class Game;

class Move {
	private:
		Tile from;
		Tile to;
		MoveType move_type;
		PieceType piece;
		PieceType promotion_piece;
	public:
		Move(std::string move, Game game);
		Tile get_from();
		Tile get_to();
};

#endif
