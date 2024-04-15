#include "MainWindow.hpp"
#include <QApplication>

using interface::MainWindow;

int main(int argc, char* argv[]) {
	QApplication app(argc, argv); 

	MainWindow mainWindow;
	mainWindow.resize(800, 800); 
	mainWindow.show(); 

	return app.exec(); 
}
