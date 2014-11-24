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
    King(PieceColor color, int row, int col) : Piece(color, KING, row, col)
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
        return pieceColor == WHITE ? "k" : "K";
    }
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif
