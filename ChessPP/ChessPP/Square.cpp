// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "GameBoard.h"
#include "Square.h"
using namespace std;

Square::Square()
{
	intRow = 0;
	intCol = 0;
	ptrPieceAtSquare = nullptr;
}

Square::Square(int row, int col, Piece* piece)
{
	intRow = row;
	intCol = col;
	ptrPieceAtSquare = piece;
}

void Square::setPieceAtSquare(Piece* piece)
{
	ptrPieceAtSquare = piece;
}

int Square::getRow() const
{
	return intRow;
}

int Square::getCol() const
{
	return intCol;
}

int Square::getRank() const
{
	return GameBoard::NUM_OF_ROWS - intRow;
}

string Square::getFile() const
{
	return string(1, 'a' + intCol);
}

Piece* Square::getPieceAtSquare() const
{
	return ptrPieceAtSquare;
}