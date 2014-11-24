// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
using namespace std;

class Knight : public Piece
{
public:
    Knight(PieceColor color, int row, int col) : Piece(color, KNIGHT, row, col) {}
    string getAbbreviation() const
    {
        return pieceColor == WHITE ? "n" : "N";
    }
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif
