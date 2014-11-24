// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "CapturedPiecesWidget.h"
#include "Game.h"
#include "MoveHistoryWidget.h"
#include "Tile.h"
#include <string>
#include <QPushButton>
using namespace std;

class GameWindow : public QWidget
{
    Q_OBJECT
private:
    Tile* arrTiles[GameBoard::NUM_OF_ROWS][GameBoard::NUM_OF_COLS];
    PieceColor colorToMove;
    bool boolIsInitialClick;
    Square initialSquare;
    Square finalSquare;
    Game* ptrGame;
    CapturedPiecesWidget* capturedPiecesWidget;
    MoveHistoryWidget* moveHistoryWidget;
    QPushButton* saveGameButton;
    void setupGUI();
    void updateGameBoard();
    string getImagePath(Piece* ptrPiece) const;
public:
    GameWindow(string strWhitePlayerName, string strBlackPlayerName);
    GameWindow(int intGameID);
private slots:
    void saveGameButtonHandler();
    void tileHandler(int intRow, int intCol);
};

#endif
