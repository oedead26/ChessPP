// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Rook.h"
using namespace std;

Rook::Rook(PieceColor color, int row, int col) : Piece(color, ROOK, row, col)
{
	boolHasBeenMoved = false;
}

void Rook::setHasBeenMoved(bool hasBeenMoved)
{
	boolHasBeenMoved = hasBeenMoved;
}

bool Rook::getHasBeenMoved() const
{
	return boolHasBeenMoved;
}

string Rook::getAbbreviation() const
{
	return pieceColor == WHITE ? "r" : "R";
}

bool Rook::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return (intVerticalMovement == 0 && intHorizontalMovement != 0) || (intVerticalMovement != 0 && intHorizontalMovement == 0);
}