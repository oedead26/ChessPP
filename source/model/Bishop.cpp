// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Bishop.h"
using namespace std;

bool Bishop::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool) const
{
	int intVerticalMovement = intFinalRow - intCurrentRow;
	int intHorizontalMovement = intFinalCol - intCurrentCol;
	return abs(intVerticalMovement) == abs(intHorizontalMovement) && intVerticalMovement != 0 && intHorizontalMovement != 0;
}
