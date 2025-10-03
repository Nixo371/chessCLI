#ifndef LOGGER_H
# define LOGGER_H

#include <ostream>

#include "piece.hpp"
#include "tile.hpp"

class Logger {
	private:

	public:
		static void print_enum(PieceType type, std::ostream& out = std::cout);
		static void print_enum(PieceColor color, std::ostream& out = std::cout);
		static void print_piece(Piece piece, std::string label = "", std::ostream& out = std::cout);
		static void print_tile(Tile tile, std::string label = "", std::ostream& out = std::cout);
		
		static void print_message(std::string message, std::ostream& out = std::cout);

		static void separator(std::ostream& out = std::cout);
};

#endif
