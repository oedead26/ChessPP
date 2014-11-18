// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Player.h"
using namespace std;

Player::Player(string name, PieceColor color)
{
	strName = name;
	pieceColor = color;
}

string Player::getName() const
{
	return strName;
}

PieceColor Player::getPieceColor() const
{
	return pieceColor;
}
