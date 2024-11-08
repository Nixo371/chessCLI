#ifndef TILE_H
# define TILE_H

#include <ostream>

#include "../piece/piece.hpp"

class Tile {
	private:
		int rank;
		int file;
		Piece piece;
		
		void set_piece(Piece piece);

	public:
		Tile();
		Tile(int rank, int file);

		void set_piece(PieceType piece, PieceColor color);
		int get_rank() const;
		int get_file() const;
		Piece get_piece() const;

		friend std::ostream& operator<< (std::ostream& out, const Tile& tile);
};

bool operator== (const Tile& tile1, const Tile& tile2);

#endif
