// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Move.h"
using namespace std;

Move::Move(Square startSquare, Square endSquare)
{
	initialSquare = startSquare;
	finalSquare = endSquare;
	boolIsPawnPromotionMove = false;
}

void Move::setIsPawnPromotionMove(bool isPawnPromotionMove)
{
	boolIsPawnPromotionMove = isPawnPromotionMove;
}

Square Move::getInitialSquare() const
{
	return initialSquare;
}

Square Move::getFinalSquare() const
{
	return finalSquare;
}

bool Move::isPawnPromotionMove() const
{
	return boolIsPawnPromotionMove;
}