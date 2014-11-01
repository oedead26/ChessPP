// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
using namespace std;

class Queen : public Piece
{
public:
	Queen(PieceColor color, int row, int col);
	string getAbbreviation() const;
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif