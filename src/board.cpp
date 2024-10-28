#include "board.hpp"

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

void Board::set_tile(int rank, int file, PieceType piece) {
	tiles[rank][file].set_piece(piece);
}


std::ostream& operator<< (std::ostream& out, const Board& board) {
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

	return (out);
}
