// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Knight.h"
using namespace std;

bool Knight::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool) const
{
	return (abs(intFinalRow - intCurrentRow) == 1 && abs(intFinalCol - intCurrentCol) == 2) ||
		(abs(intFinalRow - intCurrentRow) == 2 && abs(intFinalCol - intCurrentCol) == 1);
}
