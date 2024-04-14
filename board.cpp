#include "board.hpp"
#include <memory>
#include <iostream>
#include <algorithm>


namespace gameManagement {
	Board::Board(int i) {
		chessboard = vector<vector<Case>>(boardSize, vector<Case>(boardSize));
		chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(7, 0));
		chessboard[7][4].piece = make_unique<King>(Color::White, Pos(7, 4));
		chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(7, 3));

		chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(0, 4));
	}

	Board::Board() {
		chessboard = vector<vector<Case>>(boardSize, vector<Case>(boardSize));

		chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(7, 0));
		chessboard[7][1].piece = make_unique<Knight>(Color::White, Pos(7, 1));
		chessboard[7][2].piece = make_unique<Bishop>(Color::White, Pos(7, 2));
		chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(7, 3));
		chessboard[7][4].piece = make_unique<King>(Color::White, Pos(7, 4));
		chessboard[7][5].piece = make_unique<Bishop>(Color::White, Pos(7, 5));
		chessboard[7][6].piece = make_unique<Knight>(Color::White, Pos(7, 6));
		chessboard[7][7].piece = make_unique<Rook>(Color::White, Pos(7, 7));
		for (int i = 0; i < boardSize; i++)
			chessboard[6][i].piece = make_unique<Pawn>(Color::White, Pos(6, i));

		for (int i = 2; i < 5; i++) {
			for (int j = 0; j < boardSize; j++) {
				chessboard[i][j].piece = nullptr;
			}
		}

		chessboard[0][0].piece = make_unique<Rook>(Color::Black, Pos(0, 0));
		chessboard[0][1].piece = make_unique<Knight>(Color::Black, Pos(0, 1));
		chessboard[0][2].piece = make_unique<Bishop>(Color::Black, Pos(0, 2));
		chessboard[0][3].piece = make_unique<Queen>(Color::Black, Pos(0, 3));
		chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(0, 4));
		chessboard[0][5].piece = make_unique<Bishop>(Color::Black, Pos(0, 5));
		chessboard[0][6].piece = make_unique<Knight>(Color::Black, Pos(0, 6));
		chessboard[0][7].piece = make_unique<Rook>(Color::Black, Pos(0, 7));
		for (int i = 0; i < boardSize; i++)
			chessboard[1][i].piece = make_unique<Pawn>(Color::Black, Pos(1, i));
	}

	bool Board::isMoveAvaliable(Color color, Pos pos) {
		if (pos.x < boardSize && pos.x >= 0 && pos.y < boardSize && pos.y >= 0) {
			return &getPiece(pos) == nullptr || getPiece(pos).color != color;
		}
		return false;
	}

	bool Board::isMoveAvaliablePawn(Color color, Pos pos, Pos posPawn) {
		if (pos.x < boardSize && pos.x >= 0 && pos.y < boardSize && pos.y >= 0) {
			if (color == Color::Black) {
				if (pos - posPawn == Pos(1, 0)) {
					return &getPiece(pos) == nullptr;
				} else if (pos - posPawn == Pos(2, 0)) {
					return &getPiece(pos) == nullptr && posPawn.x == 1;
				} else if (pos - posPawn == Pos(1, 1) || pos - posPawn == Pos(1, -1)) {
					return &getPiece(pos) != nullptr && getPiece(pos).color == Color::White;
				}
				return false;
			} else {
				if (pos - posPawn == Pos(-1, 0)) {
					return &getPiece(pos) == nullptr;
				} else if (pos - posPawn == Pos(-2, 0)) {
					return &getPiece(pos) == nullptr && posPawn.x == 6;
				} else if (pos - posPawn == Pos(-1, 1) || pos - posPawn == Pos(-1, -1)) {
					return &getPiece(pos) != nullptr && getPiece(pos).color == Color::Black;
				}
				return false;
			}
		}
	}

	Piece& Board::getPiece(Pos pos) {
		return *(chessboard[pos.x][pos.y].piece.get());
	}

	void Board::lookAvaliableMoveForPlayer(Piece& piece) {
		piece.listMove = {};
		switch (getPiece(piece.pos).name) {
		case PieceName::King:
			for (int i = 0; i < getPiece(piece.pos).getMouvement().size(); i++) {
				Pos p = getPiece(piece.pos).pos + getPiece(piece.pos).getMouvement()[i];
				if (isMoveAvaliable(piece.color, p)) {
					piece.listMove.push_back(p);
				}
			}
			break;
		case PieceName::Pawn:
			for (int i = 0; i < getPiece(piece.pos).getMouvement().size(); i++) {
				Pos p = getPiece(piece.pos).pos + getPiece(piece.pos).getMouvement()[i];
				if (isMoveAvaliablePawn(piece.color, p, piece.pos)) {
					piece.listMove.push_back(p);
				}
			}
			break;
		case PieceName::Knight:
			for (int i = 0; i < getPiece(piece.pos).getMouvement().size(); i++) {
				Pos p = getPiece(piece.pos).pos + getPiece(piece.pos).getMouvement()[i];
				if (isMoveAvaliable(piece.color, p)) {
					piece.listMove.push_back(p);
				}
			}
			break;
		default:
			int compteur = 0;
			for (int i = 0; i < getPiece(piece.pos).getMouvement().size(); i++) {
				Pos p = getPiece(piece.pos).pos + getPiece(piece.pos).getMouvement()[i];
				Pos po = p;
				while (isMoveAvaliable(piece.color, po)) {
					piece.listMove.push_back(po);
					if (&getPiece(po) != nullptr)
						break;
					compteur += 1;
					po = p + getPiece(piece.pos).getMouvement()[i] * compteur;
				}
				compteur = 0;
			}
			break;
		}
	}

	Pos Board::lookForTheKing(Color color) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (&getPiece(Pos(i,j)) != nullptr && getPiece(Pos(i,j)).name == PieceName::King && getPiece(Pos(i,j)).color == color)
					return Pos(i, j);
			}
		}
	}

	bool Board::isKingChecked(Color color) {
		Pos posKing = lookForTheKing(color);
		vector<Pos> controledCaseByEnnemy = {};
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (&getPiece(Pos(i, j)) != nullptr && getPiece(Pos(i, j)).color != color){
					lookAvaliableMoveForPlayer(getPiece(Pos(i, j)));
					controledCaseByEnnemy.insert(controledCaseByEnnemy.end(), getPiece(Pos(i,j)).listMove.begin(), getPiece(Pos(i, j)).listMove.end());
				}
			}
		}
		return find(controledCaseByEnnemy.begin(), controledCaseByEnnemy.end(), posKing) != controledCaseByEnnemy.end();
	}


	bool Board::movePiece(Piece& piece, const Pos& newPos) {
		if (turn == piece.color) {
			lookAvaliableMoveForPlayer(piece);
			if (find(piece.listMove.begin(), piece.listMove.end(), newPos) != piece.listMove.end()) {

				Pos oldPos = piece.pos;

				chessboard[newPos.x][newPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
				chessboard[newPos.x][newPos.y].piece->pos = newPos;
				
				
				if (isKingChecked(piece.color)) {
					chessboard[oldPos.x][oldPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
					chessboard[oldPos.x][oldPos.y].piece->pos = oldPos;
					return false;
				}

				turn = turn == Color::White ? Color::Black : Color::White;
				return true;
			}
		}
		return false;
	}


	Board::PieceRAII::PieceRAII(Piece& p, const Pos& newP, Board& b)
		: piece(p), board(b) {
		oldPos = p.pos;
		board.movePiece(piece, newP);
		piece.pos = newP;
	}

	Board::PieceRAII::~PieceRAII() {
		board.movePieceRAII(piece, oldPos);
	}

	bool Board::movePieceRAII(Piece& piece, const Pos& newPos) {
		lookAvaliableMoveForPlayer(piece);
		if (find(piece.listMove.begin(), piece.listMove.end(), newPos) != piece.listMove.end()) {
			chessboard[newPos.x][newPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
			chessboard[newPos.x][newPos.y].piece->pos = newPos;
		}
		return false;
	}
}

