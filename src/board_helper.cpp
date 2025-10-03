#include "board_helper.hpp"

#include <vector>
#include <algorithm>

#include "move_helper.hpp"
#include "piece.hpp"
#include "logger.hpp"


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
	PieceColor color = tile.get_piece().get_color();
	PieceColor turn = PieceColor::WHITE;
	if (game.get_turn() % 2 == 1) {
		turn = PieceColor::BLACK;
	}

	if (color != turn) {
		return (false);
	}

	// Getting all possible moves within board, taking into account piece positions
	std::vector<Tile> legal_moves;
	switch (tile.get_piece().get_type()) {
		case PieceType::PAWN:
			legal_moves = MoveHelper::pawn_moves(game, tile);
			break;
		case PieceType::KNIGHT:
			legal_moves = MoveHelper::knight_moves(game, tile);
			break;
		case PieceType::BISHOP:
			legal_moves = MoveHelper::bishop_moves(game, tile);
			break;
		case PieceType::ROOK:
			legal_moves = MoveHelper::rook_moves(game, tile);
			break;
		case PieceType::QUEEN:
			legal_moves = MoveHelper::queen_moves(game, tile);
			break;
		case PieceType::KING:
			legal_moves = MoveHelper::king_moves(game, tile);
			break;
		default:
			std::cerr << "Piece not found!" << std::endl;
			break;
	}

	std::cout << "Legal Moves " << (char)(tile.get_file() + 'a') << tile.get_rank() + 1 << ": " << std::endl;
	for (Tile tile : legal_moves) {
		Logger::print_tile(tile, "> ");
	}

	//TODO
	// Check if moving results in a check
	// Check if move was en passant (handle that shit)
	// If castle, check if king moves through check

	Tile to = game.get_board().get_tile(rank, file);
	
	if (std::find(legal_moves.begin(), legal_moves.end(), to) == legal_moves.end()) {
		return (false);
	}

	return (true);
}
