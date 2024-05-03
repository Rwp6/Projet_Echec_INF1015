/**
* Implémentation de la class MainWindow crée dans MainWindow.hpp
* \file   MainWindow.cpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/


#include <QGridLayout>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QFont>
#include "MainWindow.hpp"

using gameManagement::Board;

namespace interface {
    MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
        QWidget* centralWidget = new QWidget(this);
        QGridLayout* layout = new QGridLayout(this);

        setupChessBoard();

        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                layout->addWidget(chessBoard[row][col], row, col);
            }
        }
       

        playerTurnLabel = new QLabel("Tour: Blancs", this);
        playerTurnLabel->setFont(QFont("Arial", 18)); 
        playerTurnLabel->setAlignment(Qt::AlignCenter);


        QLabel* additionalInfoLabel = new QLabel("Par: Rayan Asma et Rosalie Lamoureux", this);
        additionalInfoLabel->setFont(QFont("Arial", 13));
        additionalInfoLabel->setAlignment(Qt::AlignCenter);


        QPushButton* button1 = new QPushButton("Debut partie", this);
        QPushButton* button2 = new QPushButton("Mat Tour-Reine", this);
        QPushButton* button3 = new QPushButton("Reine vs Tour", this);

        button1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button1->setFixedSize(100, 30); 

        button2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button2->setFixedSize(100, 30);

        button3->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button3->setFixedSize(100, 30); 


        QHBoxLayout* bottomLayout = new QHBoxLayout;
        bottomLayout->addWidget(button1);
        bottomLayout->addWidget(button2);
        bottomLayout->addWidget(button3);
        bottomLayout->addWidget(playerTurnLabel);
        bottomLayout->addWidget(additionalInfoLabel);

        layout->addLayout(bottomLayout, 9, 0, 1, 8); 

  
        connect(button1, &QPushButton::clicked, this, &MainWindow::setStartingPosition);
        connect(button2, &QPushButton::clicked, this, &MainWindow::setQueenRookCheckmatePosition);
        connect(button3, &QPushButton::clicked, this, &MainWindow::setQueenVsRookPosition);

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
                if (moveSuccessful) {
                    updateChessSquareColor(selectedPiecePos->x, selectedPiecePos->y);
                    selectedPiecePos = nullopt;
                    updateChessBoardUI();
                    updateTurnLabel();  
                }
                else {
                    chessBoard[row][col]->setStyleSheet("background-color: red;");
                    QTimer::singleShot(1000, [this, row, col]() { updateChessSquareColor(row, col); });
                }
            }
            else {
                updateChessSquareColor(row, col);
                selectedPiecePos = nullopt;
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
                } else {
                    chessBoard[row][col]->setText("");
                }

            }
        }
    }

    void MainWindow::updateTurnLabel() {
        logic.isWhiteTurn() ? playerTurnLabel->setText("Tour: Blancs"): playerTurnLabel->setText("Tour: Noirs");
    }

    void MainWindow::setStartingPosition() {
        logic = Board(Situation::Beggining);
        updateChessBoardUI();
        updateTurnLabel();
    }

    void MainWindow::setQueenRookCheckmatePosition() {
        logic = Board(Situation::QueenRookCheckmate);
        updateChessBoardUI();
        updateTurnLabel();
    }

    void MainWindow::setQueenVsRookPosition() {
        logic = Board(Situation::QueenVSRook);
        updateChessBoardUI();
        updateTurnLabel();
    }
};