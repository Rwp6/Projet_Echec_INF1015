#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "board.hpp" 

using gameManagement::Board, gameManagement::boardSize, gameManagement::Situation;

namespace interface {
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        QPushButton* chessBoard[boardSize][boardSize];
        void setupChessBoard();
        Board logic = Board(Situation::Beggining);
        optional<Pos> selectedPiecePos = nullopt;
        void handleChessSquareClicked(int row, int col);
        void updateChessBoardUI();
        void updateChessSquareColor(int row, int col);
    };
    #endif
};