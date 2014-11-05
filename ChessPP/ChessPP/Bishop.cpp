// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Bishop.h"
using namespace std;

Bishop::Bishop(PieceColor color, int row, int col) : Piece(color, BISHOP, row, col) {}

string Bishop::getAbbreviation() const
{
	return pieceColor == WHITE ? "b" : "B";
}

bool Bishop::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return abs(intVerticalMovement) == abs(intHorizontalMovement) && intVerticalMovement != 0 && intHorizontalMovement != 0;
}