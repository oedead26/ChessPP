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
	bool boolIsPawnPromotionMove;
public:
	Move(Square startSquare, Square endSquare);
    void setIsPawnPromotionMove(bool isPawnPromotionMove)
    {
        boolIsPawnPromotionMove = isPawnPromotionMove;
    }
    Square getInitialSquare() const
    {
        return initialSquare;
    }
    Square getFinalSquare() const
    {
        return finalSquare;
    }
    bool isPawnPromotionMove() const
    {
        return boolIsPawnPromotionMove;
    }
};

#endif
