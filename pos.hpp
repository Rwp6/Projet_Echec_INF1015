#ifndef POS_HPP
#define POS_HPP

class Pos {
public:
	Pos() {};
	Pos(int ligne, int colonne);
	~Pos() {};
	int x;
	int y;
private:
};
#endif