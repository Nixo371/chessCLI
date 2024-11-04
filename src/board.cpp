#include "board.hpp"
#define RESET "\033[0m"        // Reset to default color
#define LIGHT_SQUARE "\033[48;5;143m" // Light tan background
#define DARK_SQUARE "\033[48;5;58m"  // Dark gray-olive background

Board::Board(int ranks, int files) {
	tiles = std::vector<std::vector<Tile>>();
	for (int rank = 0; rank < ranks; rank++) {
		tiles.push_back(std::vector<Tile>());
		for (int file = 0; file < files; file++) {
			tiles[rank].push_back(Tile(rank, file));
		}
	}
}

std::vector<std::vector<Tile>> Board::get_board() const {
	return (this->tiles);
}

void Board::set_tile(int rank, int file, PieceType piece, PieceColor color) {
	tiles[rank][file].set_piece(piece, color);
}


std::ostream& operator<< (std::ostream& out, const Board& board) {
/*
	// Print top line
	out << "┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓" << std::endl;
	// Iterate through board pieces, then a divider, then a line
	// Iterate through board pieces, then a divider, then a line
	std::vector<std::vector<Tile>> tiles = board.get_board();
	for (std::vector<Tile> rank : tiles) {
		std::cout << "┃";
		for (Tile tile : rank) {
			out << " " << tile << " " << "┃";
		}
		out << std::endl;
		if (tiles.back() != rank) {
			out << "┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫" << std::endl;
		}
	}

	// Print bottom line
	out << "┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛";
*/
	// Iterate through board pieces
	std::vector<std::vector<Tile>> tiles = board.get_board();
	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			if ((rank + file) % 2) {
				out << LIGHT_SQUARE;
			}
			else {
				out << DARK_SQUARE;
			}
			out << " " << tiles[rank][file] << " ";
		}
		out << RESET;
		out << std::endl;
	}

	return (out);
}
