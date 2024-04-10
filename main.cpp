/*
#include "Calc.hpp"
#include "CalcWindow.hpp"

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
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette entête si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
	#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par défaut.

	// cdbg.setTee(&clog);  // Décommenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du débogueur.
	
	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un résultat de test.
	#endif
	//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main après l'appel à cette fonction puisqu'il exécute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char *argv[])
{

	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv);
	initialiserBibliothequeCours(argc, argv);

	CalcWindow calcWindow;
	calcWindow.show();
	return app.exec();
}
*/


#include <iostream>
#include "board.hpp"
#include "piece.hpp"
#include "pos.hpp"
#include "color.hpp"
#include "case.hpp"

ostream& operator<< (ostream& o, const Piece& piece) {
	string c;
	string n;
	piece.color == Color::White ? c = "White" : c = "Black";
	if (piece.name == PieceName::Rook)
		n = "Rook";
	else if (piece.name == PieceName::Bishop)
		n = "Bishop";
	else if (piece.name == PieceName::Queen)
		n = "Queen";
	else if (piece.name == PieceName::King)
		n = "King";
	else if (piece.name == PieceName::Knight)
		n = "Knight";
	else
		n = "Pawn";

	return o << n << " | " << piece.getCarac() << " | " << c << " | " << "(" << piece.pos.x << "," << piece.pos.y << ")" << " | " << endl;
}

ostream& operator<< (ostream& o, const Board& board) {
	string allo;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board.chessboard[i][j].piece != nullptr) {
				allo += (board.chessboard[i][j].piece)->getCarac();
				allo += " ";
			} else {
				allo += "  ";
			}
		}
		allo += "\n";
	}
	return o << allo << endl;
}

int main() {
	Board b = Board();
	//Player bl = Player(Color::Black);
	cout << *b.chessboard[0][1].piece << b;
	b.movePiece(*b.chessboard[0][1].piece, Pos(2, 0));
	cout << *b.chessboard[2][0].piece << b ;
}

//#include "MainWindow.hpp"
//#include <QApplication>
//
//int main(int argc, char* argv[])
//{
//	QApplication app(argc, argv); 
//
//	MainWindow mainWindow;
//	mainWindow.resize(520, 520); 
//	mainWindow.show(); 
//
//	return app.exec(); 
//}
