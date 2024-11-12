#include "tile.hpp"

#define WHITE_PIECE "\033[38;5;255m"  // White piece color
#define BLACK_PIECE "\033[38;5;0m"    // Black piece color

Tile::Tile() {
	
}

Tile::Tile(int rank, int file) {
	this->rank = rank;
	this->file = file;
	this->piece = Piece(PieceType::NONE, PieceColor::WHITE);
}

// PRIVATE
void Tile::set_piece(Piece piece) {
	this->piece = piece;
}

// PUBLIC
void Tile::set_piece(PieceType piece, PieceColor color) {
	this->piece = Piece(piece, color);
}

int Tile::get_rank() const {
	return (this->rank);
}

int Tile::get_file() const {
	return (this->file);
}

Piece Tile::get_piece() const {
	return (this->piece);
}


bool operator== (const Tile& tile1, const Tile& tile2) {
	return (tile1.get_rank() == tile2.get_rank() && tile1.get_file() == tile2.get_file());
}

std::ostream& operator<< (std::ostream& out, const Tile& tile) {
	if (tile.get_piece().get_color() == PieceColor::WHITE) {
		out << WHITE_PIECE;
	}
	else {
		out << BLACK_PIECE;
	}
	out << tile.get_piece();

	return (out);
}
