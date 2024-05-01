#include "MainWindow.hpp"
#include <QApplication>

using interface::MainWindow;

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
	
int main(int argc, char* argv[]) {
	bibliotheque_cours::VerifierFuitesAllocations verifierFuitesAllocations;
	QApplication app(argc, argv); 
	initialiserBibliothequeCours(argc, argv);

	MainWindow mainWindow;
	mainWindow.resize(800, 800); 
	mainWindow.show(); 

	return app.exec(); 
}
