// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef SQUARE_H
#define SQUARE_H

#include "Piece.h"
using namespace std;

class Square
{
private:
	int intRow;
	int intCol;
	Piece* ptrPieceAtSquare;
public:
	Square();
	Square(int row, int col, Piece* piece);
    void setPieceAtSquare(Piece* piece)
    {
        ptrPieceAtSquare = piece;
    }
    int getRow() const
    {
        return intRow;
    }
    int getCol() const
    {
        return intCol;
    }
    int getRank() const;
    string getFile() const
    {
        return string(1, 'a' + intCol);
    }
    Piece* getPieceAtSquare() const
    {
        return ptrPieceAtSquare;
    }
};

#endif
