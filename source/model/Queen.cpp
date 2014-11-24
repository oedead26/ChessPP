// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Queen.h"
using namespace std;

bool Queen::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return (abs(intVerticalMovement) == abs(intHorizontalMovement) && intVerticalMovement != 0 && intHorizontalMovement != 0) ||
		((intVerticalMovement == 0 && intHorizontalMovement != 0) || (intVerticalMovement != 0 && intHorizontalMovement == 0));
}
