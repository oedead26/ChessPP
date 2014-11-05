// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "GameBoard.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include <algorithm>
using namespace std;

bool GameBoard::isObstructionBetween(Square initialSquare, Square finalSquare) const
{

}

bool GameBoard::isTeamAttackingSquare(Square square, PieceColor color) const
{

}

GameBoard::GameBoard()
{

}

void GameBoard::setPieceAt(int intRow, int intCol, Piece* ptrPiece)
{

}

void GameBoard::promotePawn(int intRow, int intCol, PieceType promotionType)
{

}

Square GameBoard::getSquare(int intRow, int intCol) const
{

}

Piece* GameBoard::getPieceAt(int intRow, int intCol) const
{

}

bool GameBoard::isMovePossible(Move potentialMove) const
{

}

bool GameBoard::isCheck(PieceColor color) const
{

}