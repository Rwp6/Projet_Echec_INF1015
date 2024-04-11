#include "board.hpp"
#include <memory>
#include <iostream>
#include <algorithm>

Board::Board(int i) {
	chessboard = vector<vector<Case>>(8, vector<Case>(8));
	chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(7, 0));
	chessboard[7][4].piece = make_unique<King>(Color::White, Pos(7, 4));
	chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(7, 3));
	
	chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(0, 4));
}

Board::Board() {
	chessboard = vector<vector<Case>>(8, vector<Case>(8));

	chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(7, 0));
	chessboard[7][1].piece = make_unique<Knight>(Color::White, Pos(7, 1));
	chessboard[7][2].piece = make_unique<Bishop>(Color::White, Pos(7, 2));
	chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(7, 3));
	chessboard[7][4].piece = make_unique<King>(Color::White, Pos(7, 4));
	chessboard[7][5].piece = make_unique<Bishop>(Color::White, Pos(7, 5));
	chessboard[7][6].piece = make_unique<Knight>(Color::White, Pos(7, 6));
	chessboard[7][7].piece = make_unique<Rook>(Color::White, Pos(7, 7));
	for (int i = 0; i < 8; i++)
		chessboard[6][i].piece = make_unique<Pawn>(Color::White, Pos(6, i));

	for (int i = 2; i < 5; i++) {
		for (int j = 0; j < 8; j++) {
			chessboard[i][j].piece = nullptr;
		}
	}

	for (int i = 0; i < 8; i++)
		chessboard[1][i].piece = make_unique<Pawn>(Color::Black, Pos(1, i));
	chessboard[0][0].piece = make_unique<Rook>(Color::Black, Pos(0, 0));
	chessboard[0][1].piece = make_unique<Knight>(Color::Black, Pos(0, 1));
	chessboard[0][2].piece = make_unique<Bishop>(Color::Black, Pos(0, 2));
	chessboard[0][3].piece = make_unique<Queen>(Color::Black, Pos(0, 3));
	chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(0, 4));
	chessboard[0][5].piece = make_unique<Bishop>(Color::Black, Pos(0, 5));
	chessboard[0][6].piece = make_unique<Knight>(Color::Black, Pos(0, 6));
	chessboard[0][7].piece = make_unique<Rook>(Color::Black, Pos(0, 7));
}

bool Board::isMoveAvaliable(Color color, Pos pos) {
	if (pos.x < 8 && pos.x > -1 && pos.y < 8 && pos.y > -1) {
		return getPiece(pos.x, pos.y) == nullptr || chessboard[pos.x][pos.y].piece.get()->color != color;
	}
	return false;
}

bool Board::isMoveAvaliablePawn(Color color, Pos pos, Pos posPawn) {
	if (pos.x < 8 && pos.x > -1 && pos.y < 8 && pos.y > -1) {
		if(color == Color::Black){
			if (pos - posPawn == Pos(1, 0)){
				return getPiece(pos.x, pos.y) == nullptr;
			} else if (pos - posPawn == Pos(2, 0)) {
				return getPiece(pos.x, pos.y) == nullptr && posPawn.x == 1;
			} else if (pos - posPawn == Pos(1, 1) || pos - posPawn == Pos(1, -1)) {
				return getPiece(pos.x, pos.y) != nullptr && getPiece(pos.x, pos.y)->color != color;
			}
			return false;
		} else {
			if (pos - posPawn == Pos(-1, 0)) {
				return getPiece(pos.x, pos.y) == nullptr;
			} else if (pos - posPawn == Pos(-2, 0)) {
				return getPiece(pos.x, pos.y) == nullptr && posPawn.x == 6;
			} else if (pos - posPawn == Pos(1, 1) || pos - posPawn == Pos(1, -1)) {
				return getPiece(pos.x, pos.y) == nullptr || getPiece(pos.x, pos.y)->color != color;
			}
			return false;
		}
	}
}

Piece* Board::getPiece(int x, int y) {
	return chessboard[x][y].piece.get();
}

void Board::lookAvaliableMoveForPlayer(Piece& piece) {
	if (getPiece(piece.pos.x, piece.pos.y)->name == PieceName::King) {
		for (int i = 0; i < getPiece(piece.pos.x, piece.pos.y)->getMouvement().size(); i++) {
			Pos p = getPiece(piece.pos.x, piece.pos.y)->pos + getPiece(piece.pos.x, piece.pos.y)->getMouvement()[i];
			if (isMoveAvaliable(piece.color, p)) {
				piece.listMove.push_back(p);
			}
		}
	} else if (getPiece(piece.pos.x, piece.pos.y)->name == PieceName::Pawn) {
		for (int i = 0; i < getPiece(piece.pos.x, piece.pos.y)->getMouvement().size(); i++) {
			Pos p = getPiece(piece.pos.x, piece.pos.y)->pos + getPiece(piece.pos.x, piece.pos.y)->getMouvement()[i];
			if (isMoveAvaliablePawn(piece.color, p, piece.pos)) {
				piece.listMove.push_back(p);
			}
			
		}
	} else if (getPiece(piece.pos.x, piece.pos.y)->name == PieceName::Knight) {
		for (int i = 0; i < getPiece(piece.pos.x, piece.pos.y)->getMouvement().size(); i++) {
			Pos p = getPiece(piece.pos.x, piece.pos.y)->pos + getPiece(piece.pos.x, piece.pos.y)->getMouvement()[i];
			if(isMoveAvaliable(piece.color, p)) {
				piece.listMove.push_back(p);
			}
		}
	} else {
		int compteur = 0;
		for (int i = 0; i < getPiece(piece.pos.x, piece.pos.y)->getMouvement().size(); i++) {
			Pos p = getPiece(piece.pos.x, piece.pos.y)->pos + getPiece(piece.pos.x, piece.pos.y)->getMouvement()[i];
			Pos po = p;
			while (isMoveAvaliable(piece.color, po)) {
				piece.listMove.push_back(po);
				compteur += 1;
				po = p + getPiece(piece.pos.x, piece.pos.y)->getMouvement()[i]*compteur;
			}
			compteur = 0;
		}
	}
}

void Board::movePiece(Piece& piece, const Pos& newPos) {
	lookAvaliableMoveForPlayer(piece);
	if (find(piece.listMove.begin(), piece.listMove.end(), newPos) != piece.listMove.end()) {
		chessboard[newPos.x][newPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
		chessboard[newPos.x][newPos.y].piece->pos = newPos;
	}
}


