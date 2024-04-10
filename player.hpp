#include "color.hpp"
#include "pos.hpp"
#include <vector>
using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player {
public:
	Player(Color color);
	~Player() = default;
	vector<Pos> avaliableMove = { Pos(2,0), Pos(1,0), Pos(1,1), Pos(1,-1) };
	Color color;
private:
};
#endif