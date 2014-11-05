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
	void setCurrentRow(int intRow);
	void setCurrentCol(int intCol);
	PieceColor getColor() const;
	PieceType getType() const;
	int getCurrentRow() const;
	int getCurrentCol() const;
	virtual string getAbbreviation() const = 0;
	virtual bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const = 0;
};

#endif