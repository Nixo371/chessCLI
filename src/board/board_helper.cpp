#include <vector>

#include "board_helper.hpp"


std::vector<Tile> BoardHelper::get_piece_mask(PieceType piece, Board board) {
	std::vector<Tile> piece_mask = std::vector<Tile>();
	for (std::vector<Tile> rank : board.get_board()) {
		for (Tile tile : rank) {
			if (tile.get_piece().get_type() == piece) {
				piece_mask.push_back(tile);
			}
		}
	}

	return (piece_mask);
}

bool BoardHelper::can_move_to(Game game, Tile tile, int rank, int file) {
	// TODO
	// Check if move leads to self-check (pinned or bad king move)
	// Check if destination is empty
	// Check if destination is opposite color (capture) (pawn shit)
	// Check en passant
	// Check if piece can actually move there
	

	return (true);
}
