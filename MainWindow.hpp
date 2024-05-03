#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
* Classe MainWindow qui s'occupe de l'affichage avec QT
* \file   MainWindow.hpp
* \author Rayan Asma et Rosalie Lamoureux
* \date   3 mai 2024
* Cree le 8 avril 2024
*/

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <optional>  
#include "board.hpp"

using namespace gameManagement;  
namespace interface {
    class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget* parent = nullptr);

    private:
        QPushButton* chessBoard[boardSize][boardSize]; 
        QLabel* playerTurnLabel;  
        Board logic = Board(Situation::Beggining); 
        std::optional<Pos> selectedPiecePos = std::nullopt;
        void setupChessBoard(); 
        void handleChessSquareClicked(int row, int col); 
        void updateChessBoardUI(); 
        void updateChessSquareColor(int row, int col); 
        void updateTurnLabel(); 
        void setStartingPosition();
        void setQueenRookCheckmatePosition();
        void setQueenVsRookPosition();
    };
}

#endif // MAINWINDOW_H
