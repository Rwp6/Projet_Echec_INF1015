#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "board.hpp" 

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    QPushButton* chessBoard[8][8]; 
    void setupChessBoard();
    Board logic;

};

#endif // MAINWINDOW_H
