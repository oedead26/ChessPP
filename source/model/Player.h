// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"
#include <string>
using namespace std;

class Player
{
private:
	string strName;
	PieceColor pieceColor;
public:
	Player(string name, PieceColor color);
    string getName() const
    {
        return strName;
    }
    PieceColor getPieceColor() const
    {
        return pieceColor;
    }
};

#endif
