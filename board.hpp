#include <vector>
#include "color.hpp"
#include "case.hpp"

class Board {
public:
	Board();
	~Board() {};
	void movePiece(Piece& piece, const Pos& newPos);

	vector<vector<Case>> chessboard;
private:
};