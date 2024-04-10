#include "piece.hpp"
#include <iostream>

Piece::Piece(Color c, Pos p, PieceName n) {
	color = c;
	pos = p;
	name = n;
}

const string Piece::getCarac() const { return ""; }
vector<Pos> Piece::getMouvement() { return {}; };


//void Piece::remove() {
//	Piece::~Piece(); //PAS SUR
//};

King::King(Color c, Pos p) : Piece(c, p, PieceName::King) {
	if (c == Color::Black)
		caracter = "\u2654";
	else {
		caracter = "\u265A";
	}
}

Queen::Queen(Color c, Pos p) : Piece(c, p, PieceName::Queen) {
	if (c == Color::Black)
		caracter = "\u2655";
	else {
		caracter = "\u265B";
	}
}

Rook::Rook(Color c, Pos p) : Piece(c, p, PieceName::Rook) {
	if (c == Color::Black)
		caracter = "\u2656";
	else {
		caracter = "\u265C";
	}
}

Bishop::Bishop(Color c, Pos p) : Piece(c, p, PieceName::Bishop) {
	if (c == Color::Black)
		caracter = "\u2657";
	else {
		caracter = "\u265D";
	}
}

Knight::Knight(Color c, Pos p) : Piece(c, p, PieceName::Knight) {
	if (c == Color::Black)
		caracter = "\u2658";
	else {
		caracter = "\u265E";
	}
}

Pawn::Pawn(Color c, Pos p) : Piece(c, p, PieceName::Pawn) {
	if (c == Color::Black)
		caracter = "\u2659";
	else {
		caracter = "\u265F";
	}
}