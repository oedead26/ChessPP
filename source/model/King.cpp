// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "King.h"
using namespace std;

bool King::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return (abs(intVerticalMovement) <= 1 && abs(intHorizontalMovement) <= 1 && (intVerticalMovement != 0 || intHorizontalMovement != 0)) ||
		(intVerticalMovement == 0 && abs(intHorizontalMovement) == 2);
}
