// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Game.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
using namespace std;

bool Game::doesMovePutTeamInCheck(Move potentialMove, PieceColor color)
{

}

Game::Game(Player white, Player black)
{

}

Game::Game(int intGameID)
{

}

void Game::saveToDatabase() const
{

}

Player Game::getWhitePlayer() const
{

}

Player Game::getBlackPlayer() const
{

}

GameBoard Game::getCurrentBoard() const
{

}

vector<Move> Game::getLegalMovesFrom(int intRow, int intCol)
{

}

bool Game::isMoveLegal(Move potentialMove)
{

}

void Game::makeMove(Move aMove, bool boolTempMove)
{

}

void Game::unmakeLastMove()
{

}

vector<string> Game::getPGNStrings()
{

}

vector<Piece*> Game::getCapturedPieces() const
{

}

bool Game::isCheckmate(PieceColor color)
{

}

bool Game::isStalemate(PieceColor color)
{

}

bool Game::isGameOver()
{

}