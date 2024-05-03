/**
* Classe Pos qui permet d'enmagasiner les positions des pièces/cases comme un couple (x,y) et qui permet également de faire plusieurs opérations pour simuler des déplacements.
* \file   board.hpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#ifndef POS_HPP
#define POS_HPP

class Pos {
public:
	Pos() {};
	Pos(int ligne, int colonne);
	Pos operator+(const Pos other) const;
	Pos operator-(const Pos other) const;
	Pos operator*(const int i) const;
	bool operator==(const Pos other) const;

	int x;
	int y;
};

#endif