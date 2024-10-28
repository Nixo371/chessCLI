#include <ostream>

#include "piece.hpp"

class Tile {
	private:
		int x;
		int y;
		Piece piece;
		
		void set_piece(Piece piece) {
			this->piece = piece;
		}

		friend std::ostream& operator<< (std::ostream& out, const Tile& tile);
	public:
		Tile(int x, int y) {
			this->x = x;
			this->y = y;
		}

		void set_piece(PieceType piece) {
			this->piece = Piece(piece);
		}

		int get_x() const {
			return (this->x);
		}

		int get_y() const {
			return (this->y);
		}

		Piece get_piece() const {
			return (this->piece);
		}
};

bool operator== (const Tile& tile1, const Tile& tile2) {
	return (tile1.get_x() == tile2.get_x() && tile1.get_y() == tile2.get_y());
}

std::ostream& operator<< (std::ostream& out, const Tile& tile) {
	out << tile.get_piece();

	return (out);
}
