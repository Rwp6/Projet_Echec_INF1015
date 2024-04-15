#ifndef BARD_HPP
#define BOARD_HPP

#include <vector>
#include "color.hpp"
#include "case.hpp"
#include "player.hpp"

namespace gameManagement {
	const int boardSize = 8;

	class Board {
	public:
		Board();
		Board(int i);
		~Board() {};
		Piece& getPiece(Pos pos);
		Pos lookForTheKing(Color color);
		bool isKingChecked(Color color);
		bool isMoveAvaliable(Color color, Pos pos);
		bool isMoveAvaliablePawn(Color color, Pos pos, Pos posPawn);
		void lookAvaliableMoveForPlayer(Piece& piece);
		bool movePiece(Piece& piece, const Pos& newPos);
		bool movePieceRAII(Piece& piece, const Pos& newPos);

		class PieceRAII {
		public:
			PieceRAII(Piece& piece, const Pos& newPos, Board& board);
			~PieceRAII();
			Pos oldPos;
			Piece& piece;
			Board& board;
		};

		Color turn = Color::White;
		vector<vector<Case>> chessboard;
		vector<vector<Case>> temp;
	private:
	};
}

#endif