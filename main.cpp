/**
* Le main du projet ChessProject
* \file   main.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mars 2024
* Cree le 8 avril 2024
*/

#include "MainWindow.hpp"
#include <QApplication>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp" 
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();
	bibliotheque_cours::executerGoogleTest(argc, argv);
#endif
}

using interface::MainWindow;

int main(int argc, char* argv[]) {
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv); 
	initialiserBibliothequeCours(argc, argv);

	MainWindow mainWindow;
	mainWindow.resize(800, 800); 
	mainWindow.show(); 

	return app.exec(); 
}


//#include <iostream>
//#include "board.hpp"
//#include "piece.hpp"
//#include "pos.hpp"
//#include "color.hpp"
//#include "case.hpp"
//
//using namespace gameManagement;
//using gameManagement::Board;
//
//ostream& operator<< (ostream& o, const Piece& piece) {
//	string c;
//	string n;
//	piece.color == Color::White ? c = "White" : c = "Black";
//	if (piece.name == PieceName::Rook)
//		n = "Rook";
//	else if (piece.name == PieceName::Bishop)
//		n = "Bishop";
//	else if (piece.name == PieceName::Queen)
//		n = "Queen";
//	else if (piece.name == PieceName::King)
//		n = "King";
//	else if (piece.name == PieceName::Knight)
//		n = "Knight";
//	else
//		n = "Pawn";
//
//	return o << n << " | " << piece.getCarac() << " | " << c << " | " << "(" << piece.pos.x << "," << piece.pos.y << ")" << " | " << endl;
//}
//
//ostream& operator<< (ostream& o, const Board& board) {
//	string boardToPrint;
//	for (int i = 0; i < 8; i++) {
//		boardToPrint += "|";
//		for (int j = 0; j < 8; j++) {
//			if (board.chessboard[i][j].piece != nullptr) {
//				boardToPrint += (board.chessboard[i][j].piece)->getCarac();
//				boardToPrint += " ";
//			} else {
//				boardToPrint += "  ";
//			}
//		}
//		boardToPrint += "|";
//		boardToPrint +=   "\n";
//	}
//	return o << boardToPrint << " ----------------" << endl;
//}
//
//int main() {
//	Board b = Board(Situation::Beggining);
//	cout << b;
//	b = Board(Situation::Test);
//	cout << b;
//}