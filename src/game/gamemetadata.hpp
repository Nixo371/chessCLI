#ifndef GAMEMETADATA_H
# define GAMEMETADATA_H

#include <vector>

#include "../tile/tile.hpp"

struct GameMetadata {
	int turn;
	std::vector<bool> castling;
	Tile en_passant;
	int half_moves;
	int full_moves;

	// Default constructor (initial game conditions)
	GameMetadata() : turn(0), castling(4, true), en_passant(Tile()), half_moves(0), full_moves(1) {}
};

#endif
