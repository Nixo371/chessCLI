class Game {
	private:
		Board board;
		int turn;
		std::vector<bool> castling;
		Tile en_passant;
		int half_moves;
		int full_moves;

	public:
		Game() {
			board = Board();
			turn = 0;
			castling = std::vector<bool>(4, true);
			en_passant = nullptr;
			half_moves = 0;
			full_moves = 1;
		}

		Game(std::string fen) {
			board = decode_board_from_fen(fen);
			
			
		}
};

