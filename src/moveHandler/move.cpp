#include <vector>
#include <algorithm>
#include <string>

#include "move.hpp"
#include "move_type.hpp"
#include "../board/board.hpp"
#include "../board/board_helper.hpp"
#include "../piece/piece.hpp"

Move::Move(std::string move, Game game) {
	// "e4"
	// "dxe4"
	// "Nf6"
	// "Bxe2"
	// "Qaxb3"
	// "O-O"
	// "Rb7+"
	// "Nf7#"
	// "Ba3c1" // Bishop from a3 to c1 (disambiguation on both rank and file)
	
	int i = 0;
	int from_rank = -1;
	int from_file = -1;
	int to_rank = -1;
	int to_file = -1;

	this->move_type = MoveType::NORMAL;
	
	// Check for special moves
	if (move.compare("O-O-O") == 0 || move.compare("0-0-0") == 0) { // Queenside castle
		this->move_type = MoveType::CASTLE_Q;
	}

	if (move.compare("O-O") == 0 || move.compare("0-0") == 0) { // Kingside castle
		this->move_type = MoveType::CASTLE_K;
	}

	// Get piece
	switch (move[i]) {
		case 'N':
			piece = PieceType::KNIGHT;
			i++;
			break;
		case 'B':
			piece = PieceType::BISHOP;
			i++;
			break;
		case 'R':
			piece = PieceType::ROOK;
			i++;
			break;
		case 'Q':
			piece = PieceType::QUEEN;
			i++;
			break;
		case 'K':
			piece = PieceType::KING;
			i++;
			break;
		default:
			piece = PieceType::PAWN;
	}	

	// Check if there is a capture
	if (move.find('x') != std::string::npos) { // is a capture
		this->move_type = MoveType::CAPTURE;
		// Calculate what type of capture
		// 	normal
		if (move[i] == 'x') {
			i++;
		}

		// 	file
		else if (move[i] >= 'a' && move[i] <= 'h') { // File discrimination
			from_file = move[i] - 'a';
			i++;
			// check if both are disambiguated
			if (move[i] >= '1' && move[i] <= '8') {
				from_rank = move[i] - '1';
				i++;
			}
		}

		// 	rank
		else if (move[i] >= '1' && move[i] <= '8') { // Rank discrimination (Only if file isn't enough)
			from_rank = move[i] - '1';
			i++;
		}
	}

	// Get position to move to
	to_file = move[i++] - 'a';
	to_rank = move[i++] - '1';

	// Check for additional data
	if (i != move.length()) {
	//	Check
		if (move[i] == '+') {
			this->move_type = MoveType::CHECK;	
		}

	//	Checkmate
		else if (move[i] == '#') {
			this->move_type = MoveType::CHECKMATE;	
		}
	
	//	Promotion
		else if (move[i] == '=') {
			this->move_type = MoveType::PROMOTION;
			i++;
			switch (move[i]) {
				case 'N':
					this->promotion_piece = PieceType::KNIGHT;
					break;
				case 'B':
					this->promotion_piece = PieceType::BISHOP;
					break;
				case 'R':
					this->promotion_piece = PieceType::ROOK;
					break;
				case 'Q':
					this->promotion_piece = PieceType::QUEEN;
					break;
			}
		}
	}

	// Figure out missing information
	int turn = game.get_turn();
	Board board = game.get_board();
	std::vector<Tile> mask;

	if (from_rank == -1 || from_file == -1) { // Only generate mask if necessary
		// Get a mask of all positions of all the pieces of the type
		mask = BoardHelper::get_piece_mask(piece, board); 
	}
	
	// Filter out positions which don't apply with discrimination
	if (from_rank == -1 && from_file != -1) { // File discrimination
		std::vector<Tile> bad_mask = std::vector<Tile>(mask);
		for (Tile tile : bad_mask) {
			if (tile.get_file() != from_file) {
				mask.erase(std::find(mask.begin(), mask.end(), tile));
			}
		}
	}

	if (from_rank != -1 && from_file == -1) { // Rank discrimination
		std::vector<Tile> bad_mask = std::vector<Tile>(mask);
		for (Tile tile : bad_mask) {
			if (tile.get_rank() != from_rank) {
				mask.erase(std::find(mask.begin(), mask.end(), tile));
			}
		}
	}
	
	// Find the piece that can move to the position and set the appropriate values
	if (from_rank == -1 || from_file == -1) {
		for (Tile tile : mask) {
			if (BoardHelper::can_move_to(game, tile, to_rank, to_file)) {
				from_rank = tile.get_rank();
				from_file = tile.get_file();
				break;
			}
		}
		if (from_rank == -1 || from_file == -1) {
			// ERROR
		}
	}

	this->from = board.get_tile(from_rank, from_file);
	this->to = board.get_tile(to_rank, to_file);
}

Tile Move::get_from() {
	return (this->from);
}

Tile Move::get_to() {
	return (this->to);
}
