#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "board.hpp" 

using gameManagement::Board, gameManagement::boardSize;

namespace interface {
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        QPushButton* chessBoard[boardSize][boardSize];
        void setupChessBoard();
        Board logic;
        optional<Pos> selectedPiecePos = std::nullopt;
        void handleChessSquareClicked(int row, int col);
        void updateChessBoardUI();
        void updateChessSquareColor(int row, int col);
    };
    #endif // MAINWINDOW_H
};