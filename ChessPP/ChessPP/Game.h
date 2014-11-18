// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "Move.h"
#include "Piece.h"
#include "Player.h"
#include <vector>
using namespace std;

class Game
{
private:
	Player* ptrWhitePlayer;
	Player* ptrBlackPlayer;
	GameBoard currentBoard;
	vector<GameBoard> vecPreviousBoards;
	vector<Move> vecPreviousMoves;
	bool doesMovePutTeamInCheck(Move potentialMove, PieceColor color);
public:
	Game(Player* ptrWhite, Player* ptrBlack);
	Game(int intGameID);
	void saveToDatabase() const;
	Player* getWhitePlayer() const;
	Player* getBlackPlayer() const;
	GameBoard getCurrentBoard() const;
	vector<Move> getLegalMovesFrom(int intRow, int intCol);
	bool isMoveLegal(Move potentialMove);
	void makeMove(Move aMove, bool boolTempMove = false);
	void unmakeLastMove();
	void promotePawn(int intRow, int intCol, PieceType promotionType);
	Move getPreviousMove() const;
	vector<string> getPGNStrings() const;
	vector<Piece*> getCapturedPieces() const;
	bool isCheckmate(PieceColor color);
	bool isStalemate(PieceColor color);
};

#endif