#ifndef POS_HPP
#define POS_HPP

class Pos {
public:
	Pos() {};
	Pos(int ligne, int colonne);
	~Pos() {};
	Pos operator+(const Pos other) const;\
	Pos operator-(const Pos other) const;
	Pos operator*(const int i) const;
	bool operator==(const Pos other) const;
	int x;
	int y;
private:
};

#endif