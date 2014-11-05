// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "King.h"
using namespace std;

King::King(PieceColor color, int row, int col) : Piece(color, KING, row, col)
{
	boolHasBeenMoved = false;
}

void King::setHasBeenMoved(bool hasBeenMoved)
{
	boolHasBeenMoved = hasBeenMoved;
}

bool King::getHasBeenMoved() const
{
	return boolHasBeenMoved;
}

string King::getAbbreviation() const
{
	return pieceColor == WHITE ? "k" : "K";
}

bool King::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return (abs(intVerticalMovement) <= 1 && abs(intHorizontalMovement) <= 1 && (intVerticalMovement != 0 || intHorizontalMovement != 0)) ||
		(intVerticalMovement == 0 && abs(intHorizontalMovement) == 2);
}