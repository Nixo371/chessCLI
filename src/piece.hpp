#ifndef PIECE_H
# define PIECE_H

#include <iostream>

enum PieceType {
	NONE,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

class Piece {
	private:
		PieceType type;

	public:
		Piece(PieceType type = NONE);
		PieceType get_type() const;
		
};
		
std::ostream& operator<< (std::ostream& out, const Piece& piece);

#endif
