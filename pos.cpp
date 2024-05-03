/**
* Implémentation de la class Pos crée dans pos.hpp
* \file   pos.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#include "pos.hpp"

Pos::Pos(int ligne, int colonne) {
	x = ligne;
	y = colonne;
}

Pos Pos::operator+(const Pos other) const {
	return Pos(x + other.x, y + other.y);
}

Pos Pos::operator-(const Pos other) const {
	return Pos(x - other.x, y - other.y);
}

Pos Pos::operator*(const int i) const {
	return Pos(x * i, y * i);
}

bool Pos::operator==(const Pos other) const {
	return x == other.x && y == other.y;
}