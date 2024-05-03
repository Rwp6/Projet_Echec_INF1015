/**
* Classe Board qui contient ou non une pièce
* \file   case.hpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#ifndef CASE_HPP
#define CASE_HPP

#include <memory>
#include "piece.hpp"
#include <tuple>

class Case {
public:
	Case() {};
	Case(Color c, unique_ptr<Piece> p, Pos po);
	Case& operator=(const Case& other);
	Case(const Case& other) { *this = other; };

	Color color;
	unique_ptr<Piece> piece = nullptr;
	Pos pos;
private:
};

#endif