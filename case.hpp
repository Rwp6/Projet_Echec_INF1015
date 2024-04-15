#ifndef CASE_HPP
#define CASE_HPP

#include "piece.hpp"
#include <tuple>
#include <memory>

class Case {
public:
	Case() {};
	Case(Color c, unique_ptr<Piece> p, Pos po);
	~Case() {};
	Case& operator=(const Case& other);
	Case(const Case& other) { *this = other; };

	Color color;
	unique_ptr<Piece> piece = nullptr;
	Pos pos;
private:
};

#endif