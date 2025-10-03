#ifndef MOVE_H
# define MOVE_H

# include <vector>

# include "move_type.hpp"
# include "tile.hpp"

class Game;

enum class Discrimination {
	NONE,
	FILE,
	RANK,
	BOTH
};

class Move {
	private:
		Tile from;
		Tile to;
		MoveType move_type;
		PieceType piece;
		Piece promotion_piece;

		bool check_castle_king(std::string move);
		bool check_castle_queen(std::string move);
		Discrimination check_move_discrimination(std::string move);
		std::vector<Tile> filter_file(std::vector<Tile> mask, int file);
		std::vector<Tile> filter_rank(std::vector<Tile> mask, int rank);
	public:
		Move(std::string move, Game game);
		Tile get_from();
		Tile get_to();
};

#endif
