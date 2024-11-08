#ifndef MOVE_TYPE_H
# define MOVE_TYPE_H

enum MoveType {
	NONE,
	NORMAL,
	CAPTURE,
	CHECK,
	CHECKMATE,
	PROMOTION,
	CASTLE_K,
	CASTLE_Q
};

#endif
