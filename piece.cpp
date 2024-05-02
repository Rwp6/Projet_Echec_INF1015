/**
* Implémentation de la classe Piece et de ses classes dérivées crée dans piece.hpp
* \file   piece.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mars 2024
* Cree le 8 avril 2024
*/

#include "piece.hpp"
#include <iostream>

Piece::Piece(Color c, Pos p, PieceName n) {
	color = c;
	pos = p;
	name = n;
}

int King::compteur_ = 0;
King::King(Color c, Pos p) : Piece(c, p, PieceName::King) {
	if (compteur_ >= 2) {
		throw std::runtime_error("Il ne peut y avoir que deux Roi sur le terrain.");
	}
	compteur_++;
	character_ = c == Color::Black ? "\u2654" : "\u2654";
	mouvement_ = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(1, -1) };
}

Queen::Queen(Color c, Pos p) : Piece(c, p, PieceName::Queen) {
	character_ = c == Color::Black ? "\u2655" : "\u265B";
	mouvement_ = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(1, -1) };
}

Rook::Rook(Color c, Pos p) : Piece(c, p, PieceName::Rook) {
	character_ = c == Color::Black ? "\u2656" : "\u265C";
	mouvement_ = { Pos(1,0), Pos(0,1), Pos(-1,0), Pos(0,-1) };
}

Bishop::Bishop(Color c, Pos p) : Piece(c, p, PieceName::Bishop) {
	character_ = c == Color::Black ? "\u2657" : "\u265D";
	mouvement_ = { Pos(1,1), Pos(-1,1), Pos(-1,-1), Pos(1,-1) };
}

Knight::Knight(Color c, Pos p) : Piece(c, p, PieceName::Knight) {
	character_ = (c == Color::Black) ? "\u2658" : "\u265E";
	mouvement_ = { Pos(2,1), Pos(2,-1), Pos(1,2), Pos(1,-2), Pos(-2,1), Pos(-2,-1), Pos(-1,2), Pos(-1,-2) };
}

Pawn::Pawn(Color c, Pos p) : Piece(c, p, PieceName::Pawn) {
	character_ = (c == Color::Black) ? "\u2659" : "\u265F";
	mouvement_ = (c == Color::Black) ? vector<Pos>{Pos(2, 0), Pos(1, 0), Pos(1, 1), Pos(1, -1)} : vector<Pos>{Pos(-2, 0), Pos(-1, 0), Pos(-1, 1), Pos(-1, -1)};
}