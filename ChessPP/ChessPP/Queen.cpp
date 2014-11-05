// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Queen.h"
using namespace std;

Queen::Queen(PieceColor color, int row, int col) : Piece(color, QUEEN, row, col) {}

string Queen::getAbbreviation() const
{
	return pieceColor == WHITE ? "q" : "Q";
}

bool Queen::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return (abs(intVerticalMovement) == abs(intHorizontalMovement) && intVerticalMovement != 0 && intHorizontalMovement != 0) ||
		((intVerticalMovement == 0 && intHorizontalMovement != 0) || (intVerticalMovement != 0 && intHorizontalMovement == 0));
}