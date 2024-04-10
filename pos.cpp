#include "pos.hpp"

Pos::Pos(int ligne, int colonne) {
	x = ligne;
	y = colonne;
}

Pos Pos::operator+(const Pos other) const {
	return Pos(x + other.x, y + other.y);
}

Pos Pos::operator*(const int i) const {
	return Pos(x + i * 1, y + i * 1);
}

bool Pos::operator==(const Pos other) const {
	return x == other.x && y == other.y;
}