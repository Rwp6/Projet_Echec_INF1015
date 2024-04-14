#ifndef PIECE_HPP
#define PIECE_HPP

#include "color.hpp"
#include <tuple>
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
	Color color;
	Pos pos;
	PieceName name;
	virtual const string getCarac() const;
	virtual vector<Pos> getMouvement();
	vector<Pos> listMove = {};
private:
};




class King : public Piece {
public:
	King(Color c, Pos p);
	~King() { compteur_ -= 1; };
	const string getCarac() const override { return caracter; };
	vector<Pos> getMouvement() override { return mouvement; };
	string caracter;
	vector<Pos> mouvement = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(1, -1) };
	vector<Pos> listMove;
private:
	static int compteur_;
};

class Queen : public Piece {
public:
	Queen(Color c, Pos p);
	~Queen() {};
	const string getCarac() const override { return caracter; };
	vector<Pos> getMouvement() override { return mouvement; };
	string caracter;
	vector<Pos> mouvement = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(1, -1) };
	vector<Pos> listMove;
private:
};

class Rook : public Piece {
public:
	Rook(Color c, Pos p);
	~Rook() {};
	const string getCarac() const override { return caracter; };
	vector<Pos> getMouvement() override { return mouvement; };
	string caracter;
	vector<Pos> mouvement = { Pos(1,0), Pos(0,1), Pos(-1,0), Pos(0,-1) };
	vector<Pos> listMove;

private:
};

class Bishop : public Piece {
public:
	Bishop(Color c, Pos p);
	~Bishop() {};
	const string getCarac() const override { return caracter; };
	vector<Pos> getMouvement() override { return mouvement; };
	string caracter;
	vector<Pos> mouvement = { Pos(1,1), Pos(-1,1), Pos(-1,-1), Pos(1,-1) };
	vector<Pos> listMove;

private:
};

class Knight : public Piece {
public:
	Knight(Color c, Pos p);
	~Knight() {};
	const string getCarac() const override { return caracter; };
	vector<Pos> getMouvement() override { return mouvement; };
	string caracter;
	vector<Pos> mouvement = { Pos(2,1), Pos(2,-1), Pos(1,2), Pos(1,-2), Pos(-2,1), Pos(-2,-1), Pos(-1,2), Pos(-1,-2) };
	vector<Pos> listMove;
private:
};

class Pawn : public Piece {
public:
	Pawn(Color c, Pos p);
	~Pawn() {};
	const string getCarac() const override { return caracter; };
	vector<Pos> getMouvement() override { return mouvement; };
	string caracter;
	vector<Pos> mouvement;
	vector<Pos> listMove;
private:
};
#endif