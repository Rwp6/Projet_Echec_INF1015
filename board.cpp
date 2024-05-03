/**
* Implémentation de la classe Board crée dans board.hpp
* \file   board.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#include <iostream>
#include <algorithm>
#include <memory>
#include "board.hpp"


namespace gameManagement {
	Board::Board(Situation situation) {
		try {
			chessboard = vector<vector<Case>>(boardSize, vector<Case>(boardSize));
			King::deleteAllKings();
			switch (situation) {
			case gameManagement::Situation::Beggining:
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
				break;

			case gameManagement::Situation::QueenRookCheckmate:
				chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(7, 0));
				chessboard[7][4].piece = make_unique<King>(Color::White, Pos(7, 4));
				chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(7, 3));

				chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(0, 4));
				break;
			case gameManagement::Situation::QueenVSRook:
				chessboard[1][5].piece = make_unique<Queen>(Color::White, Pos(1, 5));
				chessboard[3][3].piece = make_unique<King>(Color::White, Pos(3, 3));

				chessboard[2][1].piece = make_unique<Rook>(Color::Black, Pos(2, 1));
				chessboard[0][3].piece = make_unique<King>(Color::Black, Pos(0, 3));
				break;
			case gameManagement::Situation::Test:
				chessboard[7][0].piece = make_unique<Rook>(Color::White, Pos(7, 0));
				chessboard[7][1].piece = make_unique<Knight>(Color::White, Pos(7, 1));
				chessboard[7][2].piece = make_unique<Bishop>(Color::White, Pos(7, 2));
				chessboard[7][3].piece = make_unique<Queen>(Color::White, Pos(7, 3));
				chessboard[6][5].piece = make_unique<Pawn>(Color::White, Pos(6, 5));

				chessboard[0][0].piece = make_unique<Rook>(Color::Black, Pos(0, 0));
				chessboard[0][1].piece = make_unique<Knight>(Color::Black, Pos(0, 1));
				chessboard[0][2].piece = make_unique<Bishop>(Color::Black, Pos(0, 2));
				chessboard[0][3].piece = make_unique<Queen>(Color::Black, Pos(0, 3));
				chessboard[0][4].piece = make_unique<King>(Color::Black, Pos(0, 4));
				chessboard[1][5].piece = make_unique<Pawn>(Color::Black, Pos(1, 5));
				chessboard[2][0].piece = make_unique<Pawn>(Color::Black, Pos(2, 0));
			default:
				break;
			}

		} catch (const runtime_error& e) {
			cerr << "Erreur : " << e.what() << endl;
		}
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
					return &getPiece(pos) != nullptr && getPiece(pos).color == !color;
				}
			} else {
				if (pos - posPawn == Pos(-1, 0)) {
					return &getPiece(pos) == nullptr;
				} else if (pos - posPawn == Pos(-2, 0)) {
					return &getPiece(pos) == nullptr && posPawn.x == 6;
				} else if (pos - posPawn == Pos(-1, 1) || pos - posPawn == Pos(-1, -1)) {
					return &getPiece(pos) != nullptr && getPiece(pos).color == !color;
				}
			}
		}
		return false;
	}

	Piece& Board::getPiece(Pos pos) {
		return *chessboard[pos.x][pos.y].piece.get();
	}

	void Board::lookAvaliableMoveForPlayer(Piece& piece) {
		piece.listMove = {};
		switch (getPiece(piece.pos).name) {
		case PieceName::King:
		case PieceName::Knight:
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
		default:
			int multiplicator = 0;
			for (int i = 0; i < getPiece(piece.pos).getMouvement().size(); i++) {
				Pos p = getPiece(piece.pos).pos + getPiece(piece.pos).getMouvement()[i];
				Pos po = p;
				while (isMoveAvaliable(piece.color, po)) {
					piece.listMove.push_back(po);
					if (&getPiece(po) != nullptr)
						break;
					multiplicator += 1;
					po = p + getPiece(piece.pos).getMouvement()[i] * multiplicator;
				}
				multiplicator = 0;
			}
			break;
		}
	}

	Pos Board::lookForTheKing(Color color) {
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (&getPiece(Pos(i, j)) != nullptr && getPiece(Pos(i, j)).name == PieceName::King && getPiece(Pos(i, j)).color == color)
					return Pos(i, j);
			}
		}
	}

	bool Board::isKingChecked(Color color) {
		Pos posKing = lookForTheKing(color);
		vector<Pos> controledCaseByEnnemy = {};
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				if (&getPiece(Pos(i, j)) != nullptr && getPiece(Pos(i, j)).color != color) {
					lookAvaliableMoveForPlayer(getPiece(Pos(i, j)));
					controledCaseByEnnemy.insert(controledCaseByEnnemy.end(), getPiece(Pos(i, j)).listMove.begin(), getPiece(Pos(i, j)).listMove.end());
				}
			}
		}
		return find(controledCaseByEnnemy.begin(), controledCaseByEnnemy.end(), posKing) != controledCaseByEnnemy.end();
	}


	bool Board::movePiece(Piece& piece, const Pos& finalPos) {
		if (turn == piece.color) {
			lookAvaliableMoveForPlayer(piece);
			if (find(piece.listMove.begin(), piece.listMove.end(), finalPos) != piece.listMove.end()) {

				Pos oldPos = piece.pos;
				unique_ptr<Piece> oldPiece = move(chessboard[finalPos.x][finalPos.y].piece);

				chessboard[finalPos.x][finalPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
				chessboard[finalPos.x][finalPos.y].piece->pos = finalPos;

				if (isKingChecked(piece.color)) {
					chessboard[oldPos.x][oldPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
					chessboard[oldPos.x][oldPos.y].piece->pos = oldPos;

					chessboard[finalPos.x][finalPos.y].piece = move(oldPiece);
					return false;
				}

				turn = !turn;
				return true;
			}
		}
		return false;
	}

	Board::PieceRAII::PieceRAII(Piece& piece, const Pos& finalPos, Board& board)
		: piece(piece), board(board) {
		oldPos = piece.pos;
		board.movePieceRAII(piece, finalPos);
		piece.pos = finalPos;
	}

	Board::PieceRAII::~PieceRAII() {
		board.chessboard[oldPos.x][oldPos.y].piece = move(board.chessboard[piece.pos.x][piece.pos.y].piece);
		board.chessboard[oldPos.x][oldPos.y].piece->pos = oldPos;
	}

	bool Board::movePieceRAII(Piece& piece, const Pos& finalPos) {
		lookAvaliableMoveForPlayer(piece);
		if (find(piece.listMove.begin(), piece.listMove.end(), finalPos) != piece.listMove.end()) {
			chessboard[finalPos.x][finalPos.y].piece = move(chessboard[piece.pos.x][piece.pos.y].piece);
			chessboard[finalPos.x][finalPos.y].piece->pos = finalPos;
			return true;
		}
		return false;
	}

	bool Board::isWhiteTurn() const {
		return turn == Color::White;
	}
}

