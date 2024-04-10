#include "MainWindow.hpp"
#include <QGridLayout>
#include <QWidget>


QColor creamColor("#F5F5DC");
QColor darkGrayColor("#A9A9A9");

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    QWidget* centralWidget = new QWidget(this); 
    QGridLayout* layout = new QGridLayout; 

    

    setupChessBoard(); 

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            layout->addWidget(chessBoard[row][col], row, col); 
        }
    }

    centralWidget->setLayout(layout); 
    setCentralWidget(centralWidget); 
}

void MainWindow::setupChessBoard()
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            chessBoard[row][col] = new QPushButton; 
            chessBoard[row][col]->setFixedSize(64, 64); 

        
            QColor color = ((row + col) % 2 == 0) ? creamColor : darkGrayColor;
            chessBoard[row][col]->setStyleSheet(QString("background-color: %1;").arg(color.name()));
        }
    }
}
