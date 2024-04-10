#include "MainWindow.hpp"
#include <QGridLayout>
#include <QWidget>



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

void MainWindow::setupChessBoard() {

    
    QColor light("#E2CAA1");
    QColor dark("#6F6B64");
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            chessBoard[row][col] = new QPushButton(this);
            chessBoard[row][col]->setFixedSize(64, 64); 

            
            auto piece = logic.chessboard[row][col].piece.get(); 
            if (piece != nullptr) {
                QString pieceUnicode = QString::fromStdString(piece->getCarac());
                chessBoard[row][col]->setText(pieceUnicode);
            }

            QFont font = chessBoard[row][col]->font();
            font.setPointSize(20); 
            chessBoard[row][col]->setFont(font);

            QColor color = ((row + col) % 2 == 0) ? light : dark;
            chessBoard[row][col]->setStyleSheet(QString("background-color: %1;").arg(color.name()));
            

            
        }
    }

}

