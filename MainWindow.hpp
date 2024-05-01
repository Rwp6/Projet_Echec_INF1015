#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>  // S'assurer que QLabel est inclus
#include "board.hpp"

using gameManagement::Board, gameManagement::boardSize, gameManagement::Situation;

namespace interface {
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        QPushButton* chessBoard[boardSize][boardSize];
        QLabel* playerTurnLabel;  // Ajouter ce membre pour le label du tour
        void setupChessBoard();
        Board logic = Board(Situation::Test);
        optional<Pos> selectedPiecePos = nullopt;
        void handleChessSquareClicked(int row, int col);
        void updateChessBoardUI();
        void updateChessSquareColor(int row, int col);
        void updateTurnLabel();  // Ajouter une méthode pour mettre à jour le label
    };
}
#endif
