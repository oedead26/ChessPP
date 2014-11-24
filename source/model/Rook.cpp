// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Rook.h"
using namespace std;

bool Rook::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return (intVerticalMovement == 0 && intHorizontalMovement != 0) || (intVerticalMovement != 0 && intHorizontalMovement == 0);
}
