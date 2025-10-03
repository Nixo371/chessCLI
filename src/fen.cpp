#include <iostream>

#include "fen.hpp"
#include "board.hpp"

// PRIVATE
Board FEN::decode_board_bfen(std::string board_fen) {
	// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR

	Board board = Board();

	int rank = 7;
	int file = 0;

	for (char c : board_fen) {
		PieceColor color = PieceColor::WHITE;
		if (c >= 'a' && c <= 'z') {
			color = PieceColor::BLACK;
		}

		switch (c) {
			case 'p':
			case 'P':
				board.set_tile(rank, file, PieceType::PAWN, color);
				file++;
				break;
			case 'n':
			case 'N':
				board.set_tile(rank, file, PieceType::KNIGHT, color);
				file++;
				break;
			case 'b':
			case 'B':
				board.set_tile(rank, file, PieceType::BISHOP, color);
				file++;
				break;
			case 'r':
			case 'R':
				board.set_tile(rank, file, PieceType::ROOK, color);
				file++;
				break;
			case 'q':
			case 'Q':
				board.set_tile(rank, file, PieceType::QUEEN, color);
				file++;
				break;
			case 'k':
			case 'K':
				board.set_tile(rank, file, PieceType::KING, color);
				file++;
				break;
			case '/':
				rank--;
				file = 0;
				break;
			default: // in the case of a number
				file += (c - '0');
		}
	}

	return (board);
}

GameMetadata FEN::decode_metadata_mfen(std::string metadata_fen) {
	// w KQkq - 0 1

	GameMetadata meta;

	int i = 0;

	// Get player turn
	if (metadata_fen[i] == 'w')
		meta.turn = 0;
	else
		meta.turn = 1;
	i += 2; // skip the space

	// Get castle rights
	meta.castling = std::vector<bool>(4, false);
	while (metadata_fen[i] != ' ') {
		switch (metadata_fen[i]) {
			case 'K':
				meta.castling[0] = true;
				break;
			case 'Q':
				meta.castling[1] = true;
				break;
			case 'k':
				meta.castling[2] = true;
				break;
			case 'q':
				meta.castling[3] = true;
				break;
			case '-': // there are no castling rights
				break;
		}
		i++;
	}
	i++; // Skip the space

	// Get en passant square
	if (metadata_fen[i] == '-') {
		meta.en_passant = Tile();
	}
	else {
		int rank = metadata_fen[i] - 'a';
		i++;
		int file = metadata_fen[i] - '0';
		i++;

		meta.en_passant = Tile(rank, file);
	}
	i++; // Skip the space

	std::string turn_counters = metadata_fen.substr(i);
	std::string half_moves = turn_counters.substr(0, turn_counters.length() - turn_counters.find(' '));
	std::string full_moves = turn_counters.substr(turn_counters.find(' ') + 1);

	meta.half_moves = atoi(half_moves.data());
	meta.full_moves = atoi(full_moves.data());

	return (meta);
}

// PUBLIC
Board FEN::decode_board(std::string fen) {
	std::string board_fen = fen.substr(0, fen.find(' '));

	std::cout << "Board FEN: [" << board_fen << "]" << std::endl;
	return (FEN::decode_board_bfen(board_fen));
}

GameMetadata FEN::decode_metadata(std::string fen) {
	std::string metadata_fen = fen.substr(fen.find(' ') + 1);

	std::cout << "Metadata FEN: [" << metadata_fen << "]" << std::endl;
	return (FEN::decode_metadata_mfen(metadata_fen));
}
