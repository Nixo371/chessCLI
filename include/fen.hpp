#ifndef FEN_H
# define FEN_H

# include <string>
# include <stdlib.h>

# include "gamemetadata.hpp"

class Board;

class FEN {
	private:
		static Board decode_board_bfen(std::string board_fen);
		static GameMetadata decode_metadata_mfen(std::string metadata_fen);
	
	public:
		static Board decode_board(std::string fen);
		static GameMetadata decode_metadata(std::string fen);
};

#endif
