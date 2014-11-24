// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Square.h"
#include "GameBoard.h"
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

int Square::getRank() const
{
	return GameBoard::NUM_OF_ROWS - intRow;
}
