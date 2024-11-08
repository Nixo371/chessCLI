#include "piece.hpp"


Piece::Piece(PieceType type, PieceColor color) {
	this->type = type;
	this->color = color;
}

PieceType Piece::get_type() const {
	return (this->type);
}

PieceColor Piece::get_color() const {
	return (this->color);
}

std::ostream& operator<< (std::ostream& out, const Piece& piece) {
	std::string p;
	switch (piece.get_type()) {
		case PAWN:
			p = "♙";
			break;
		case KNIGHT:
			p = "♘";
			break;
		case BISHOP: 
			p = "♗";
			break;
		case ROOK:
			p = "♖";
			break;
		case QUEEN:
			p = "♕";
			break;
		case KING:
			p = "♔";
			break;
		default:
			p = " ";
	}
	out << p;
	return (out);
}
