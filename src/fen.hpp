#include <string>

#include "game.hpp"

class FEN {
	private:
		void decode_board(std::string board_fen, Board board) {
		
		}

		void decode_metadata(std::string metadata_fen, Game game) {
		
		}
	public:
		static Game decode(std::string fen) {
			Game game = Game();
			Board board = game.get_board();
			
			std::string board_fen = fen.substr(0, fen.find(" "));
			std::cout << "Board FEN: " << board_fen << "|" << std::endl;

			decode_board(board_fen, board);
			
			std::string metadata_fen = fen.substr(fen.find(" ") + 1, fen.length());
			std::cout << "Metadata FEN: " << metadata_fen << "|" << std::endl;

			decode_metadata(metadata_fen, game);

			return (game);
		}
}
