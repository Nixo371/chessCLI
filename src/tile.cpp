#include "tile.hpp"

Tile::Tile() {
	
}

Tile::Tile(int rank, int file) {
	this->rank = rank;
	this->file = file;
}

// PRIVATE
void Tile::set_piece(Piece piece) {
	this->piece = piece;
}

// PUBLIC
void Tile::set_piece(PieceType piece) {
	this->piece = Piece(piece);
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
	out << tile.get_piece();

	return (out);
}
