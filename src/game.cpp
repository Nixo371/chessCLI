#include "game.hpp"

#include "fen.hpp"
#include "logger.hpp"

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

	if (from.get_rank() == -1 || to.get_rank() == -1) {
		Logger::print_message("Invalid move!\n");
		return (false);
	}

	Logger::print_tile(from, "From: ");
	Logger::separator();
	Logger::print_tile(to, "To: ");
	Logger::separator();
	
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

Tile Game::get_en_passant() {
	return (this->metadata.en_passant);
}

std::ostream& operator<< (std::ostream& out, const Game& game) {
	out << game.get_board();

	return (out);
}
