// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef CHESSUI_H
#define CHESSUI_H

#include "Game.h"
#include "Player.h"
using namespace std;

class ChessUI
{
private:
	Game* ptrGame;
public:
	void startGame();
	void displayPostTurnInfo(const Player* ptrPlayer) const;
	void displayMoveHistory() const;
	void displayCapturedPieces() const;
	void displayGameBoard() const;
	void displayCheckWarning(const Player* ptrPlayer) const;
	void displayGameOverMessage() const;
};

#endif