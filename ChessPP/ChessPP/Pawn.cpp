// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Pawn.h"
using namespace std;

Pawn::Pawn(PieceColor color, int row, int col) : Piece(color, PAWN, row, col)
{
	ptrEnPassantCaptureSquare = nullptr;
}

void Pawn::setEnPassantCaptureSquare(Square* ptrSquare)
{
	ptrEnPassantCaptureSquare = ptrSquare;
}

Square* Pawn::getEnPassantCaptureSquare() const
{
	return ptrEnPassantCaptureSquare;
}

string Pawn::getAbbreviation() const
{
	if (pieceType == KNIGHT)
	{
		return pieceColor == WHITE ? "n" : "N";
	}
	else if (pieceType == BISHOP)
	{
		return pieceColor == WHITE ? "b" : "B";
	}
	else if (pieceType == ROOK)
	{
		return pieceColor == WHITE ? "r" : "R";
	}
	else if (pieceType == QUEEN)
	{
		return pieceColor == WHITE ? "q" : "Q";
	}
	return pieceColor == WHITE ? "p" : "P";
}

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