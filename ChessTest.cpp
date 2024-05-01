#include "board.hpp"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

using namespace gameManagement;

TEST(Board, deplacement_tour_blanc_au_debut) {
	Board b = Board(Situation::Test);
	Piece* pieceBeforeMove = &b.getPiece(Pos(7, 0));
	b.movePiece(*pieceBeforeMove, Pos(5, 0));
	Piece* pieceAfterMove = &b.getPiece(Pos(5, 0));
	
	EXPECT_EQ(pieceAfterMove, pieceBeforeMove);
}

TEST(Board, deplacement_cavalier_blanc_au_debut) {
	Board b = Board(Situation::Test);
	Piece* pieceBeforeMove = &b.getPiece(Pos(7, 1));
	b.movePiece(*pieceBeforeMove, Pos(5, 2));
	Piece* pieceAfterMove = &b.getPiece(Pos(5, 2));

	EXPECT_EQ(pieceAfterMove, pieceBeforeMove);
}

TEST(Board, deplacement_fou_blanc_au_debut) {
	Board b = Board(Situation::Test);
	Piece* pieceBeforeMove = &b.getPiece(Pos(7, 2));
	b.movePiece(*pieceBeforeMove, Pos(5, 4));
	Piece* pieceAfterMove = &b.getPiece(Pos(5, 4));

	EXPECT_EQ(pieceAfterMove, pieceBeforeMove);
}

TEST(Board, deplacement_pion_blanc_2_cases) {
	Board b = Board(Situation::Test);
	Piece* pieceBeforeMove = &b.getPiece(Pos(6, 5));
	b.movePiece(*pieceBeforeMove, Pos(4, 5));
	Piece* pieceAfterMove = &b.getPiece(Pos(4, 5));

	EXPECT_EQ(pieceAfterMove, pieceBeforeMove);
}

TEST(Board, deplacement_pion_blanc_2_cases_pas_possible) {
	Board b = Board(Situation::Test);
	b.movePiece(b.getPiece(Pos(6, 5)), Pos(5, 5));
	b.movePiece(b.getPiece(Pos(1, 5)), Pos(2, 5));
	Piece* pieceBeforeMove = &b.getPiece(Pos(5, 5));
	b.movePiece(*pieceBeforeMove, Pos(3, 5));

	EXPECT_EQ(pieceBeforeMove, pieceBeforeMove);
}

TEST(Board, pas_deplacement_piece_noir_au_debut) {
	Board b = Board(Situation::Test);
	Piece* pieceBeforeMove = &b.getPiece(Pos(0, 0));
	b.movePiece(*pieceBeforeMove, Pos(2, 0));

	EXPECT_EQ(pieceBeforeMove, pieceBeforeMove);
}

TEST(Board, mise_en_echec_deplacement_limite_pour_roi_noir) {
	Board b = Board(Situation::Test);
	b.movePiece(b.getPiece(Pos(7,3)), Pos(7, 4));
	Piece* pieceBeforeMove = &b.getPiece(Pos(0, 4));
	b.movePiece(*pieceBeforeMove, Pos(1, 4));

	EXPECT_EQ(pieceBeforeMove, pieceBeforeMove);
}

#endif
