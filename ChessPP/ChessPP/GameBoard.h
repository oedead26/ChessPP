// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Move.h"
#include "Piece.h"
#include "Square.h"
using namespace std;

class GameBoard
{
public:
	static const int NUM_OF_ROWS = 8;
	static const int NUM_OF_COLS = 8;
private:
	Square arrSquares[NUM_OF_ROWS][NUM_OF_COLS];
	bool isObstructionBetween(Square initialSquare, Square finalSquare) const;
	bool isTeamAttackingSquare(Square square, PieceColor color) const;
public:
	GameBoard();
	void setPieceAt(int intRow, int intCol, Piece* ptrPiece);
	void promotePawn(int intRow, int intCol, PieceType type);
	Square getSquare(int intRow, int intCol) const;
	Piece* getPieceAt(int intRow, int intCol) const;
	bool isMovePossible(Move potentialMove) const;
	bool isCheck(PieceColor color) const;
};

#endif