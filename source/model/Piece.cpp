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
