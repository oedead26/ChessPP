// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
using namespace std;

class Bishop : public Piece
{
public:
    Bishop(PieceColor color, int row, int col) : Piece(color, BISHOP, row, col) {}
    string getAbbreviation() const
    {
        return pieceColor == WHITE ? "b" : "B";
    }
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif
