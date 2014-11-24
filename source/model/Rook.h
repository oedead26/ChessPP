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
    Rook(PieceColor color, int row, int col) : Piece(color, ROOK , row, col)
    {
        boolHasBeenMoved = false;
    }
    void setHasBeenMoved(bool hasBeenMoved)
    {
        boolHasBeenMoved = hasBeenMoved;
    }
    bool getHasBeenMoved() const
    {
        return boolHasBeenMoved;
    }
    string getAbbreviation() const
    {
        return pieceColor == WHITE ? "r" : "R";
    }
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif
