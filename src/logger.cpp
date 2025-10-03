#include "logger.hpp"

#include <map>

std::map<PieceType, std::string> piece_types{
	{PieceType::PAWN, "Pawn"},
	{PieceType::KNIGHT, "Knight"},
	{PieceType::BISHOP, "Bishop"},
	{PieceType::ROOK, "Rook"},
	{PieceType::QUEEN, "Queen"},
	{PieceType::KING, "King"},
	{PieceType::NONE, "None"}
};

std::map<PieceColor, std::string> piece_colors{
	{PieceColor::WHITE, "White"},
	{PieceColor::BLACK, "Black"}
};

void Logger::print_enum(PieceType type, std::ostream& out) {
	out << piece_types[type];
}
void Logger::print_enum(PieceColor color, std::ostream& out) {
	out << piece_colors[color];
}

void Logger::print_piece(Piece piece, std::string label, std::ostream& out) {
	out << label;
	Logger::print_enum(piece.get_type());
	out << " ";
	Logger::print_enum(piece.get_color());
	out << std::endl;
}

void Logger::print_tile(Tile tile, std::string label, std::ostream& out) {
	out << label;
	char file = tile.get_file() + 'a';
	int rank = tile.get_rank() + 1;

	out << file << rank << std::endl;
	Logger::print_piece(tile.get_piece());
}

void Logger::print_message(std::string message, std::ostream& out) {
	out << message;
}

void Logger::separator(std::ostream& out) {
	out << "---" << std::endl;
}
