#include <vector>
#include <ostream>

#include "tile.hpp"

class Board {
	private:
		std::vector<std::vector<Tile>> tiles;
	public:
		Board(int ranks = 8, int files = 8) {
			tiles = std::vector<std::vector<Tile>>();
			for (int rank = 0; rank < ranks; rank++) {
				tiles.push_back(std::vector<Tile>());
				for (int file = 0; file < files; file++) {
					tiles[rank].push_back(Tile(rank, file));
				}
			}
		}

		std::vector<std::vector<Tile>> get_board() const {
			return (this->tiles);
		}
		friend std::ostream& operator<< (std::ostream& out, const Board& board);
		
};

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
