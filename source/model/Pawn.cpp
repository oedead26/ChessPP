// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Pawn.h"
using namespace std;

bool Pawn::isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const
{
	int intDirectionMultiplier = pieceColor == WHITE ? -1 : 1;
	// Pawn moves one square forward
	if (intFinalRow == intCurrentRow + intDirectionMultiplier && intFinalCol == intCurrentCol)
	{
		return !boolIsFinalSquareOccupied;
	}
	// Pawn moves two squares forward
	else if (intFinalRow == intCurrentRow + 2 * intDirectionMultiplier && intFinalCol == intCurrentCol)
	{
		int intStartingRank = pieceColor == WHITE ? 6 : 1;
		return intCurrentRow == intStartingRank && !boolIsFinalSquareOccupied;
	}
	// Pawn moves diagonally
	else if (intFinalRow == intCurrentRow + intDirectionMultiplier && abs(intFinalCol - intCurrentCol) == 1)
	{
		// If the final square is NOT occupied, the move must be an en passant capture
		if (!boolIsFinalSquareOccupied)
		{
			if (ptrEnPassantCaptureSquare == nullptr)
			{
				return false;
            }
			return intFinalRow == ptrEnPassantCaptureSquare->getRow() && intFinalCol == ptrEnPassantCaptureSquare->getCol();
		}
		return true;
	}
	return false;
}
