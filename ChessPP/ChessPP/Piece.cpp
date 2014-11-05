// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Piece.h"
using namespace std;

Piece::Piece(PieceColor color, PieceType type, int row, int col)
{
	pieceColor = color;
	pieceType = type;
	intCurrentRow = row;
	intCurrentCol = col;
}

void Piece::setCurrentRow(int intRow)
{
	intCurrentRow = intRow;
}

void Piece::setCurrentCol(int intCol)
{
	intCurrentCol = intCol;
}

PieceColor Piece::getColor() const
{
	return pieceColor;
}

PieceType Piece::getType() const
{
	return pieceType;
}

int Piece::getCurrentRow() const
{
	return intCurrentRow;
}

int Piece::getCurrentCol() const
{
	return intCurrentCol;
}