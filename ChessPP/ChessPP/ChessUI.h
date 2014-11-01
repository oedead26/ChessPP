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
	Game* game;
public:
	ChessUI();
	void startGame();
	void displayPostTurnInfo(const Player* player) const;
	void displayMoveHistory() const;
	void displayCapturedPieces() const;
	void displayGameBoard() const;
	void displayCheckWarning(const Player* player) const;
	void displayGameOverMessage() const;
};

#endif