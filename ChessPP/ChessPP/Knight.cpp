// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Knight.h"
using namespace std;

Knight::Knight(PieceColor color, int row, int col) : Piece(color, KNIGHT, row, col) {}

string Knight::getAbbreviation() const
{
	return pieceColor == WHITE ? "n" : "N";
}

bool Knight::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const
{
	return (abs(intFinalRow - intCurrentRow) == 1 && abs(intFinalCol - intCurrentCol) == 2) ||
		(abs(intFinalRow - intCurrentRow) == 2 && abs(intFinalCol - intCurrentCol) == 1);
}