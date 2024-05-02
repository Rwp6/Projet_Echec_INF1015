/**
* Implémentation de la classe Case crée dans case.hpp
* \file   case.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mars 2024
* Cree le 8 avril 2024
*/

#include "case.hpp"

Case::Case(Color c, unique_ptr<Piece> p, Pos po) {
	color = c;
	piece = move(p);
	pos = po;
}

Case& Case::operator=(const Case& other) {
	if (this != &other) {
		color = other.color;
		piece = other.piece ? make_unique<Piece>(*other.piece) : nullptr; 
		pos = other.pos;
	}
	return *this;
}
