#include "MainWindow.hpp"
#include <QGridLayout>
#include <QWidget>
#include <QTimer>



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
    layout->setRowStretch(8, 1);
    layout->setColumnStretch(8, 1);
    centralWidget->setLayout(layout); 
    setCentralWidget(centralWidget); 
}

void MainWindow::setupChessBoard() {

    
    QColor light("#6C6C6C");
    QColor dark("#292626");
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            chessBoard[row][col] = new QPushButton(this);
            chessBoard[row][col]->setFixedSize(100, 100); 

            
            auto piece = logic.chessboard[row][col].piece.get(); 
            if (piece != nullptr) {
                QString pieceUnicode = QString::fromStdString(piece->getCarac());
                chessBoard[row][col]->setText(pieceUnicode);
            }

            QFont font = chessBoard[row][col]->font();
            font.setPointSize(40); 
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
            chessBoard[row][col]->setStyleSheet("background-color: #FFD700;");
        }
    }
    else {
        if (selectedPiecePos->x != row || selectedPiecePos->y != col) {
            bool moveSuccessful = logic.movePiece(*(logic.chessboard[selectedPiecePos->x][selectedPiecePos->y].piece), Pos(row, col));
            if (!moveSuccessful) {
                chessBoard[row][col]->setStyleSheet("background-color: red;");
                QTimer::singleShot(1000, [this, row, col]() { updateChessSquareColor(row, col); }); 
            }
            updateChessSquareColor(selectedPiecePos->x, selectedPiecePos->y);
            selectedPiecePos = std::nullopt;
            updateChessBoardUI();
        }
        else {
            updateChessSquareColor(row, col);
            selectedPiecePos = std::nullopt;
        }
    }
}

void MainWindow::updateChessSquareColor(int row, int col) {
    QColor light("#6C6C6C");
    QColor dark("#292626");
    QColor color = ((row + col) % 2 == 0) ? light : dark;
    chessBoard[row][col]->setStyleSheet(QString("background-color: %1;").arg(color.name()));
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
