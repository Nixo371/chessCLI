#include "piece.hpp"

std::ostream& operator<< (std::ostream& out, const Piece& piece) {
	out << (char)piece.get_type();

	return (out);
}
