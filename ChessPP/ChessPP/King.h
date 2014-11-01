// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef KING_H
#define KING_H

#include "Piece.h"
using namespace std;

class King : public Piece
{
private:
	bool boolHasBeenMoved;
public:
	King(PieceColor color, int row, int col);
	void setHasBeenMoved(bool hasBeenMoved);
	bool getHasBeenMoved() const;
	string getAbbreviation() const;
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif