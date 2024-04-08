#include "board.hpp"
#include <memory>

Board::Board() {
	chessboard = vector<vector<Case>>(8, vector<Case>(8));

	chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(0, 0));
	chessboard[7][1].piece = make_unique<Knight>(Color::White, Pos(0, 1));
	chessboard[7][2].piece = make_unique<Bishop>(Color::White, Pos(0, 2));
	chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(0, 3));
	chessboard[7][4].piece = make_unique<King>(Color::White, Pos(0, 4));
	chessboard[7][5].piece = make_unique<Bishop>(Color::White, Pos(0, 5));
	chessboard[7][6].piece = make_unique<Knight>(Color::White, Pos(0, 6));
	chessboard[7][7].piece = make_unique<Rook>(Color::White, Pos(0, 7));
	for (int i = 0; i < 8; i++)
		chessboard[6][i].piece = make_unique<Pawn>(Color::White, Pos(0, i));
	for (int i = 0; i < 8; i++)
		chessboard[1][i].piece = make_unique<Pawn>(Color::Black, Pos(6, i));
	chessboard[0][0].piece = make_unique<Rook>(Color::Black, Pos(7, 0));
	chessboard[0][1].piece = make_unique<Knight>(Color::Black, Pos(7, 1));
	chessboard[0][2].piece = make_unique<Bishop>(Color::Black, Pos(7, 2));
	chessboard[0][3].piece = make_unique<Queen>(Color::Black, Pos(7, 3));
	chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(7, 4));
	chessboard[0][5].piece = make_unique<Bishop>(Color::Black, Pos(7, 5));
	chessboard[0][6].piece = make_unique<Knight>(Color::Black, Pos(7, 6));
	chessboard[0][7].piece = make_unique<Rook>(Color::Black, Pos(7, 7));
}



