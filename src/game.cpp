#include "game.hpp"
#include "fen.hpp"

Game::Game() {
	this->board = Board();
	this->metadata = GameMetadata();
}

Game::Game(std::string fen) {
	this->board = FEN::decode_board(fen);
	this->metadata = FEN::decode_metadata(fen);
}

Board Game::get_board() const {
	return (this->board);
}


std::ostream& operator<< (std::ostream& out, const Game& game) {
	out << game.get_board();

	return (out);
}
