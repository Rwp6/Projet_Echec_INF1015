#ifndef BARD_HPP
#define BOARD_HPP

#include <vector>
#include "color.hpp"
#include "case.hpp"
#include "player.hpp"

class Board {
public:
	Board();
	Board(int i);
	~Board() {};
	Piece* getPiece(int x, int y);
	bool isMoveAvaliable(Color color, Pos pos);
	bool isMoveAvaliablePawn(Color color, Pos pos, Pos posPawn);
	void lookAvaliableMoveForPlayer(Piece& piece);
	bool movePiece(Piece& piece, const Pos& newPos);

	vector<vector<Case>> chessboard;
private:
};

#endif