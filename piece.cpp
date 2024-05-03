/**
* Implémentation de la classe Piece et de ses classes dérivées crée dans piece.hpp
* \file   piece.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#include <iostream>
#include "piece.hpp"

Piece::Piece(Color c, Pos p) {
	color = c;
	pos = p;
}

int King::compteur_ = 0;

King::King(Color c, Pos p) : Piece(c, p) {
	if (compteur_ >= 2) {
		throw std::runtime_error("Il ne peut y avoir que deux Rois sur le terrain.");
	}
	name = PieceName::King;
	compteur_++;
	character_ = c == Color::Black ? "\u2654" : "\u265A";
	mouvement_ = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(1, -1) };
}

void King::deleteAllKings() {
	compteur_ = 0;
}

Queen::Queen(Color c, Pos p) : Piece(c, p) {
	name = PieceName::Queen;
	character_ = c == Color::Black ? "\u2655" : "\u265B";
	mouvement_ = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(1, -1) };
}

Rook::Rook(Color c, Pos p) : Piece(c, p) {
	name = PieceName::Rook;
	character_ = c == Color::Black ? "\u2656" : "\u265C";
	mouvement_ = { Pos(1,0), Pos(0,1), Pos(-1,0), Pos(0,-1) };
}

Bishop::Bishop(Color c, Pos p) : Piece(c, p) {
	name = PieceName::Bishop;
	character_ = c == Color::Black ? "\u2657" : "\u265D";
	mouvement_ = { Pos(1,1), Pos(-1,1), Pos(-1,-1), Pos(1,-1) };
}

Knight::Knight(Color c, Pos p) : Piece(c, p) {
	name = PieceName::Knight;
	character_ = (c == Color::Black) ? "\u2658" : "\u265E";
	mouvement_ = { Pos(2,1), Pos(2,-1), Pos(1,2), Pos(1,-2), Pos(-2,1), Pos(-2,-1), Pos(-1,2), Pos(-1,-2) };
}

Pawn::Pawn(Color c, Pos p) : Piece(c, p) {
	name = PieceName::Pawn;
	character_ = (c == Color::Black) ? "\u2659" : "\u265F";
	mouvement_ = (c == Color::Black) ? vector<Pos>{Pos(2, 0), Pos(1, 0), Pos(1, 1), Pos(1, -1)} : vector<Pos>{Pos(-2, 0), Pos(-1, 0), Pos(-1, 1), Pos(-1, -1)};
}