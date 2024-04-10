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

    
    QColor light("#F50B0B");
    QColor dark("#292626");
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
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            connect(chessBoard[row][col], &QPushButton::clicked, [this, row, col]() {
                this->handleChessSquareClicked(row, col);
                });
        }
    }
}

void MainWindow::handleChessSquareClicked(int row, int col) {
    if (!selectedPiecePos) {
        if (logic.chessboard[row][col].piece != nullptr) { 
            selectedPiecePos = Pos(row, col); 
            
        }
    }
    else {
        if (selectedPiecePos->x != row || selectedPiecePos->y != col) { 
            logic.movePiece(*(logic.chessboard[selectedPiecePos->x][selectedPiecePos->y].piece), Pos(row, col));
            selectedPiecePos = std::nullopt; 
            updateChessBoardUI(); 
        }
    }
}
void MainWindow::updateChessBoardUI() {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            auto& piece = logic.chessboard[row][col].piece;

            if (piece) {
                QString pieceUnicode = QString::fromStdString(piece->getCarac());
                chessBoard[row][col]->setText(pieceUnicode);
            }
            else {
                chessBoard[row][col]->setText("");
            }

        }
    }
}
