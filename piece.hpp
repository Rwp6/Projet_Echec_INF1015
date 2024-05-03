/**
* Classe Piece et ses dérivées qui définie l'apparence, le comportement et le nom d'une pièce. Enmagasine également la position et la liste des mouvements possible pour une pièce
* \file   piece.hpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#ifndef PIECE_HPP
#define PIECE_HPP

#include "color.hpp"
#include <vector>
#include <string>
#include "pos.hpp"

using namespace std;

enum class PieceName {
	Rook,
	Knight,
	Bishop,
	Queen,
	King,
	Pawn,
	None
};

class Piece {
public:
	Piece() {};
	Piece(Color c, Pos p, PieceName n);
	virtual ~Piece() {};
	const string getCarac() const { return character_; };
	vector<Pos> getMouvement() { return mouvement_; };

	Color color;
	Pos pos;
	PieceName name;
	vector<Pos> listMove;
protected:
	string character_;
	vector<Pos> mouvement_;
};

class King : public Piece {
public:
	King(Color c, Pos p);
	~King() { compteur_ -= 1; };
	static void deleteAllKings();
private:
	static int compteur_;
};

class Queen : public Piece {
public:
	Queen(Color c, Pos p);
	~Queen() {};
};

class Rook : public Piece {
public:
	Rook(Color c, Pos p);
	~Rook() {};
};

class Bishop : public Piece {
public:
	Bishop(Color c, Pos p);
	~Bishop() {};
};

class Knight : public Piece {
public:
	Knight(Color c, Pos p);
	~Knight() {};
};

class Pawn : public Piece {
public:
	Pawn(Color c, Pos p);
	~Pawn() {};
};

#endif