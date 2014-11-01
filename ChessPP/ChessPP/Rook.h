// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
using namespace std;

class Rook : public Piece
{
private:
	bool boolHasBeenMoved;
public:
	Rook(PieceColor color, int row, int col);
	void setHasBeenMoved(bool hasBeenMoved);
	bool getHasBeenMoved() const;
	string getAbbreviation() const;
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif