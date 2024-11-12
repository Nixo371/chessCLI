#include <vector>
#include <algorithm>
#include <string>

#include "move.hpp"
#include "move_type.hpp"
#include "../board/board.hpp"
#include "../board/board_helper.hpp"
#include "../piece/piece.hpp"

Move::Move(std::string move, Game game) {
	int i = 0;
	int from_rank = -1;
	int from_file = -1;
	int to_rank = -1;
	int to_file = -1;

	this->move_type = MoveType::NORMAL;
	
	// Check for special moves
	if (check_castle_king(move)) {
		this->move_type = MoveType::CASTLE_K;
	}
	if (check_castle_queen(move)) {
		this->move_type = MoveType::CASTLE_Q;
	}

	// Get piece to move
	piece = Piece::decode_piece_type(move[i]);
	if (piece != PieceType::PAWN)
		i++;

	// Check if there is a capture
	if (move.find('x') != std::string::npos) { // is a capture
		this->move_type = MoveType::CAPTURE;
		// Check for discrimination
		Discrimination discrimination = check_move_discrimination(move.substr(i));
		
		// "[...][file][rank]x[...]"
		switch (discrimination) {
			case Discrimination::NONE:
				i++;
				break;
			case Discrimination::FILE:
				from_file = move[i++] - 'a';
				break;
			case Discrimination::RANK:
				from_rank = move[i++] - '1';
				break;
			case Discrimination::BOTH:
				from_file = move[i++] - 'a';
				from_rank = move[i++] - '1';
				break;
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
			this->promotion_piece = Piece::decode_piece_type(move[i]);
		}
		else {
			// What
		}
	}

	// Figure out missing information
	int turn = game.get_turn();
	Board board = game.get_board();
	std::vector<Tile> piece_mask;

	if (from_rank == -1 || from_file == -1) { // Only generate mask if necessary
		// Get a mask of all positions of all the pieces of the type
		piece_mask = BoardHelper::get_piece_mask(piece, board); 
	}
	
	// Filter out positions which don't apply with discrimination
	if (from_rank == -1 && from_file != -1) { // File discrimination
		piece_mask = filter_rank(piece_mask, from_rank);
	}

	if (from_rank != -1 && from_file == -1) { // Rank discrimination
		piece_mask = filter_rank(piece_mask, from_rank);
	}
	
	// Find the piece that can move to the position and set the appropriate values
	if (from_rank == -1 || from_file == -1) {
		for (Tile tile : piece_mask) {
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

bool Move::check_castle_king(std::string move) {
	return (move.compare("O-O") == 0 || move.compare("0-0") == 0);
}

bool Move::check_castle_queen(std::string move) {
	return (move.compare("O-O-O") == 0 || move.compare("0-0-0") == 0);
}

Discrimination Move::check_move_discrimination(std::string move) {
	int i = 0;
	if (move[i] >= 'a' && move[i] <= 'h') { // File discrimination
		i++;
		// check if both are disambiguated
		if (move[i] >= '1' && move[i] <= '8') {
			return (Discrimination::BOTH);
		}
		return (Discrimination::FILE);
	}
	else if (move[i] >= '1' && move[i] <= '8') { // Rank discrimination (Only if file isn't enough)
		return (Discrimination::RANK);
	}
	return (Discrimination::NONE);
}

std::vector<Tile> Move::filter_file(std::vector<Tile> mask, int file) {
	std::vector<Tile> bad_mask = std::vector<Tile>(mask);
	for (Tile tile : bad_mask) {
		if (tile.get_file() != file) {
			mask.erase(std::find(mask.begin(), mask.end(), tile));
		}
	}

	return (mask);
}

std::vector<Tile> Move::filter_rank(std::vector<Tile> mask, int rank) {
	std::vector<Tile> bad_mask = std::vector<Tile>(mask);
	for (Tile tile : bad_mask) {
		if (tile.get_rank() != rank) {
			mask.erase(std::find(mask.begin(), mask.end(), tile));
		}
	}

	return (mask);
}

Tile Move::get_from() {
	return (this->from);
}

Tile Move::get_to() {
	return (this->to);
}
