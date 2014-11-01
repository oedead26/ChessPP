// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef MOVE_H
#define MOVE_H

#include "Square.h"
using namespace std;

class Move
{
private:
	Square initialSquare; // A pointer to the Piece making the move will ALWAYS reside here
	Square finalSquare;  // A pointer to the Piece captured during the move will ALWAYS reside here
public:
	Move(Square startSquare, Square endSquare);
	Square getInitialSquare() const;
	Square getFinalSquare() const;
};

#endif