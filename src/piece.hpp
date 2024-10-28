#include <iostream>

enum PieceType {
	NONE = ' ',
	PAWN = '♙',
	KNIGHT = '♘',
	BISHOP = '♗',
	ROOK = '♖',
	QUEEN = '♕',
	KING = '♔'
};

class Piece {
	private:
		PieceType type;

	public:
		Piece(PieceType type = NONE) {
			this->type = type;
		}

		PieceType get_type() const {
			return (this->type);
		}

};


std::ostream& operator<< (std::ostream& out, const Piece& piece);
