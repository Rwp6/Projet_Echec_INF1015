/**
* Classe Pos qui permet d'enmagasiner les positions des pi�ces/cases comme un couple (x,y) et qui permet �galement de faire plusieurs op�rations pour simuler des d�placements.
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