#ifndef PIECE_H
# define PIECE_H

#include <iostream>

enum PieceType {
	EMPTY,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum PieceColor {
	WHITE,
	BLACK
};

class Piece {
	private:
		PieceType type;
		PieceColor color;

	public:
		Piece(PieceType type = PieceType::EMPTY, PieceColor color = PieceColor::WHITE);
		PieceType get_type() const;
		PieceColor get_color() const;
		
};
		
std::ostream& operator<< (std::ostream& out, const Piece& piece);

#endif
