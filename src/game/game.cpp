#include "game.hpp"
#include "../fen/fen.hpp"

Game::Game() {
	this->board = Board();
	this->metadata = GameMetadata();
}

Game::Game(std::string fen) {
	this->board = FEN::decode_board(fen);
	this->metadata = FEN::decode_metadata(fen);
}

bool Game::play_move(Move move) {
	Tile from = move.get_from();
	Tile to = move.get_to();
	
	this->board.set_tile(to.get_rank(), to.get_file(), from.get_piece().get_type(), from.get_piece().get_color());
	this->board.set_tile(from.get_rank(), from.get_file(), PieceType::NONE, PieceColor::WHITE);

	this->metadata.turn = (this->metadata.turn + 1) % 2;
	this->metadata.half_moves++;
	this->metadata.full_moves++;

	return (true);
}

Board Game::get_board() const {
	return (this->board);
}

int Game::get_turn() {
	return (this->metadata.turn);
}

std::ostream& operator<< (std::ostream& out, const Game& game) {
	out << game.get_board();

	return (out);
}
