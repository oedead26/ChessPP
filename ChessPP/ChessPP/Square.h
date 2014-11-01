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
	void setPieceAtSquare(Piece* piece);
	int getRow() const;
	int getCol() const;
	int getRank() const;
	string getFile() const;
	Piece* getPieceAtSquare() const;
};

#endif