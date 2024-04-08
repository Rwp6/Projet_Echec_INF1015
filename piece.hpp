#include "color.hpp"
#include <tuple>
#include <string>
#include "pos.hpp"

using namespace std;

#ifndef PIECE_HPP
#define PIECE_HPP

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
	virtual Piece* getPiece();
	virtual const string getCarac() const;
	//virtual void move();
	//void remove();
	//void add();
private:
};

class King : public Piece {
public:
	King(Color c, Pos p);
	~King() {};
	King* getPiece() override { return this; };
	const string getCarac() const override{ return caracter; };
	string caracter;
	Pos mouvement[8] = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(-1, -1)};
private:
};

class Queen : public Piece {
public:
	Queen(Color c, Pos p);
	~Queen() {};
	Queen* getPiece() override { return this; };
	const string getCarac() const override { return caracter; };
	string caracter;
	Pos mouvement[8] = { Pos(1,0), Pos(1,1), Pos(0,1), Pos(-1,1), Pos(-1,0), Pos(-1,-1), Pos(0,-1), Pos(-1, -1)};
private:
};

class Rook : public Piece {
public:
	Rook(Color c, Pos p);
	~Rook() {};
	Rook* getPiece() override { return this; };
	const string getCarac() const override { return caracter; };
	string caracter;
	Pos mouvement[4] = { Pos(1,0), Pos(0,1), Pos(-1,0), Pos(0,-1)};
private:
};

class Bishop : public Piece {
public:
	Bishop(Color c, Pos p);
	~Bishop() {};
	Bishop* getPiece() override { return this; };
	const string getCarac() const override { return caracter; };
	string caracter;
	Pos mouvement[4] = { Pos(1,1), Pos(-1,1), Pos(-1,-1), Pos(1,-1) };
private:
};

class Knight : public Piece {
public:
	Knight(Color c, Pos p);
	~Knight() {};
	Knight* getPiece() override { return this; };
	const string getCarac() const override { return caracter; };
	string caracter;
	Pos mouvement[8] = { Pos(2,1), Pos(2,-1), Pos(1,2), Pos(1,-2), Pos(-2,1), Pos(-2,-1), Pos(-1,2), Pos(-1,-2) };
private:
};

class Pawn : public Piece {
public:
	Pawn(Color c, Pos p);
	~Pawn() {};
	Pawn* getPiece() override { return this; };
	const string getCarac() const override { return caracter; };
	string caracter;
	Pos mouvement[4] = { Pos(2,0), Pos(1,0), Pos(1,1), Pos(1,-1) };
private:
};
#endif