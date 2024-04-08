#include <vector>
#include "color.hpp"
#include "case.hpp"

class Board {
public:
	Board();
	~Board() {};
	vector<vector<Case>> chessboard;
private:
};