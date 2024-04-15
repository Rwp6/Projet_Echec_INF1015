#include "case.hpp"

Case::Case(Color c, unique_ptr<Piece> p, Pos po) {
	color = c;
	piece = move(p);
	pos = po;
}

Case& Case::operator=(const Case& other) {
	if (this != &other) {
		color = other.color;
		piece = other.piece ? make_unique<Piece>(*other.piece) : nullptr; // Copy the Piece object if it exists
		pos = other.pos;
	}
	return *this;
}
