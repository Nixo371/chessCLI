#include "move_helper.hpp"
#include "piece.hpp"

std::vector<Tile> MoveHelper::pawn_moves(Game game, Tile from) {
	std::vector<Tile> legal_moves;

	Board board = game.get_board();
	int rank = from.get_rank();
	int file = from.get_file();
	PieceColor color = from.get_piece().get_color();
	int dir = 1; // White default

	// Advancing
	if (color == PieceColor::BLACK) {
		dir = -1;
	}
	Tile advance = board.get_tile(rank + 1 * dir, file);
	Tile advance_start = board.get_tile(rank + 2 * dir, file);
	
	if (advance.get_piece().get_type() == PieceType::NONE) {
		legal_moves.push_back(advance);
	}

	if ((color == PieceColor::WHITE && rank == 1) || (color == PieceColor::BLACK && rank == 6)) {
		if (advance_start.get_piece().get_type() == PieceType::NONE) {
			legal_moves.push_back(advance_start);
		}
	}

	// Captures
	Tile capture_left = board.get_tile(rank + 1, file - 1);
	Tile capture_right = board.get_tile(rank + 1, file + 1);

	if (capture_left.get_rank() != -1 && capture_left.get_piece().get_type() != PieceType::NONE && capture_left.get_piece().get_color() != color) {
		legal_moves.push_back(capture_left);
	}

	if (capture_right.get_rank() != -1 && capture_right.get_piece().get_type() != PieceType::NONE && capture_right.get_piece().get_color() != color) {
		legal_moves.push_back(capture_right);
	}
	// En Passant
	if (capture_left == game.get_en_passant()) {
		legal_moves.push_back(capture_left);
	}
	if (capture_right == game.get_en_passant()) {
		legal_moves.push_back(capture_right);
	}

	return (legal_moves);
}

std::vector<Tile> MoveHelper::knight_moves(Game game, Tile from) {
	std::vector<Tile> legal_moves;

	Board board = game.get_board();
	int rank = from.get_rank();
	int file = from.get_file();
	PieceColor color = from.get_piece().get_color();
	std::vector<Tile> possible_moves({
			board.get_tile(rank + 2, file + 1),
			board.get_tile(rank + 2, file - 1),
			board.get_tile(rank - 2, file + 1),
			board.get_tile(rank - 2, file - 1),
			board.get_tile(rank + 1, file + 2),
			board.get_tile(rank + 1, file - 2),
			board.get_tile(rank - 1, file + 2),
			board.get_tile(rank - 1, file - 2)
	});

	for (Tile move : possible_moves) {
		if (move.get_rank() == -1) {
			continue;
		}
		if (move.get_piece().get_type() != PieceType::NONE && move.get_piece().get_color() == color) {
			continue;
		}
		legal_moves.push_back(move);
	}

	return (legal_moves);
}

std::vector<Tile> MoveHelper::bishop_moves(Game game, Tile from) {
	std::vector<Tile> legal_moves;

	Board board = game.get_board();
	int rank = from.get_rank();
	int file = from.get_file();
	PieceColor color = from.get_piece().get_color();

	std::vector<std::pair<int, int>> dirs({
			{-1, -1},
			{-1, 1},
			{1, -1},
			{1, 1}
	});
	
	for (std::pair<int, int> dir : dirs) {
		int dist = 1;
		while (true) {
			Tile move = board.get_tile(rank + dist * dir.first, file + dist * dir.second);

			if (move.get_rank() == -1) { // Out of bounds
				break;
			}
			
			if (move.get_piece().get_type() != PieceType::NONE) {
				if (move.get_piece().get_color() == color) {
					break;
				}
				else {
					legal_moves.push_back(move);
					continue;
				}
			}

			legal_moves.push_back(move);

			dist++;
		}
	}

	return (legal_moves);
}

// TODO
// Test this
std::vector<Tile> MoveHelper::rook_moves(Game game, Tile from) {
	std::vector<Tile> legal_moves;

	Board board = game.get_board();
	int rank = from.get_rank();
	int file = from.get_file();
	PieceColor color = from.get_piece().get_color();

	std::vector<std::pair<int, int>> dirs({
			{-1, 0},
			{1, 0},
			{0, -1},
			{0, 1}
	});

	for (std::pair<int, int> dir : dirs) {
		int dist = 1;
		while (true) {
			Tile move = board.get_tile(rank + dist * dir.first, file + dist * dir.second);

			if (move.get_rank() == -1) { // Out of bounds
				break;
			}
			
			if (move.get_piece().get_type() != PieceType::NONE) {
				if (move.get_piece().get_color() == color) {
					break;
				}
				else {
					legal_moves.push_back(move);
					continue;
				}
			}

			legal_moves.push_back(move);

			dist++;
		}
	}

	return (legal_moves);
}

// TODO
// Test this
std::vector<Tile> MoveHelper::queen_moves(Game game, Tile from) {
	std::vector<Tile> legal_moves;

	Board board = game.get_board();
	int rank = from.get_rank();
	int file = from.get_file();
	PieceColor color = from.get_piece().get_color();

	std::vector<std::pair<int, int>> dirs({
			{-1, -1},
			{-1, 1},
			{1, -1},
			{1, 1},
			{-1, 0},
			{1, 0},
			{0, -1},
			{0, 1}
	});

	for (std::pair<int, int> dir : dirs) {
		int dist = 1;
		while (true) {
			Tile move = board.get_tile(rank + dist * dir.first, file + dist * dir.second);

			if (move.get_rank() == -1) { // Out of bounds
				break;
			}
			
			if (move.get_piece().get_type() != PieceType::NONE) {
				if (move.get_piece().get_color() == color) {
					break;
				}
				else {
					legal_moves.push_back(move);
					continue;
				}
			}

			legal_moves.push_back(move);

			dist++;
		}
	}

	return (legal_moves);
}

// TODO
// Test this
std::vector<Tile> MoveHelper::king_moves(Game game, Tile from) {
	std::vector<Tile> legal_moves;

	Board board = game.get_board();
	int rank = from.get_rank();
	int file = from.get_file();
	PieceColor color = from.get_piece().get_color();
	std::vector<Tile> possible_moves({
			board.get_tile(rank + 1, file + 1),
			board.get_tile(rank + 1, file + 0),
			board.get_tile(rank + 1, file - 1),
			board.get_tile(rank + 0, file + 1),
			board.get_tile(rank + 0, file - 1),
			board.get_tile(rank - 1, file + 1),
			board.get_tile(rank - 1, file + 0),
			board.get_tile(rank - 1, file - 1)
	});

	// TODO
	// Somehow check for castling and add it to the list
	// Cannot be fucked to add this right now

	for (Tile move : possible_moves) {
		if (move.get_rank() == -1) {
			continue;
		}
		if (move.get_piece().get_color() == color) {
			continue;
		}
		legal_moves.push_back(move);
	}

	return (legal_moves);
}
