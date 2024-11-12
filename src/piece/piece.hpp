#ifndef PIECE_H
# define PIECE_H

#include <iostream>
#include <unordered_map>

enum class PieceType {
	NONE,
	PAWN,
	KNIGHT,
	BISHOP,
	ROOK,
	QUEEN,
	KING
};

enum class PieceColor {
	WHITE,
	BLACK
};

class Piece {
	private:
		PieceType type;
		PieceColor color;
		static const std::unordered_map<char, Piece> piece_map;
	public:
		Piece(PieceType type = PieceType::NONE, PieceColor color = PieceColor::WHITE);
		PieceType get_type() const;
		PieceColor get_color() const;
		
		static PieceType decode_piece_type(char piece);
};
		
std::ostream& operator<< (std::ostream& out, const Piece& piece);

#endif
