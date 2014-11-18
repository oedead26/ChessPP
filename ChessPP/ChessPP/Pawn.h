// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include "Square.h"
using namespace std;

class Pawn : public Piece
{
private:
	Square* ptrEnPassantCaptureSquare;
public:
	Pawn(PieceColor color, int row, int col);
	void setEnPassantCaptureSquare(Square* ptrSquare);
	Square* getEnPassantCaptureSquare() const;
	string getAbbreviation() const;
	bool isCapableOfMovingTo(int intFinalRow, int intFinalCol, bool boolIsFinalSquareOccupied) const;
};

#endif