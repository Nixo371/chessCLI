#include "piece.hpp"

const std::unordered_map<char, Piece> Piece::piece_map = {
	{'P', Piece(PieceType::PAWN, PieceColor::WHITE)},
	{'N', Piece(PieceType::KNIGHT, PieceColor::WHITE)},
	{'B', Piece(PieceType::BISHOP, PieceColor::WHITE)},
	{'R', Piece(PieceType::ROOK, PieceColor::WHITE)},
	{'Q', Piece(PieceType::QUEEN, PieceColor::WHITE)},
	{'K', Piece(PieceType::KING, PieceColor::WHITE)},
	{'p', Piece(PieceType::PAWN, PieceColor::BLACK)},
	{'n', Piece(PieceType::KNIGHT, PieceColor::BLACK)},
	{'b', Piece(PieceType::BISHOP, PieceColor::BLACK)},
	{'r', Piece(PieceType::ROOK, PieceColor::BLACK)},
	{'q', Piece(PieceType::QUEEN, PieceColor::BLACK)},
	{'k', Piece(PieceType::KING, PieceColor::BLACK)}
};

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

PieceType Piece::decode_piece_type(char piece) {
	if (piece_map.count(piece) == 0) {
		return (PieceType::PAWN);
	}
	Piece p = piece_map.at(piece);

	return (p.get_type());

}

std::ostream& operator<< (std::ostream& out, const Piece& piece) {
	std::string p;
	switch (piece.get_type()) {
		case PieceType::PAWN:
			p = "♙";
			break;
		case PieceType::KNIGHT:
			p = "♘";
			break;
		case PieceType::BISHOP: 
			p = "♗";
			break;
		case PieceType::ROOK:
			p = "♖";
			break;
		case PieceType::QUEEN:
			p = "♕";
			break;
		case PieceType::KING:
			p = "♔";
			break;
		default:
			p = " ";
	}
	out << p;
	return (out);
}
