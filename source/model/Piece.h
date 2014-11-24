// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

enum PieceColor
{
	WHITE, BLACK
};

enum PieceType
{
	PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
};

class Piece
{
protected:
	PieceColor pieceColor;
	PieceType pieceType;
	int intCurrentRow;
	int intCurrentCol;
public:
	Piece(PieceColor color, PieceType type, int row, int col);
    void setCurrentRow(int intRow)
    {
        intCurrentRow = intRow;
    }
    void setCurrentCol(int intCol)
    {
        intCurrentCol = intCol;
    }
    PieceColor getColor() const
    {
        return pieceColor;
    }
    PieceType getType() const
    {
        return pieceType;
    }
    int getCurrentRow() const
    {
        return intCurrentRow;
    }
    int getCurrentCol() const
    {
        return intCurrentCol;
    }
	virtual string getAbbreviation() const = 0;
	virtual bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const = 0;
};

#endif
