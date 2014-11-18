// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Game.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
using namespace std;

bool Game::doesMovePutTeamInCheck(Move potentialMove, PieceColor color)
{
	bool boolMovePutsTeamInCheck = false;
	makeMove(potentialMove, true);
	if (currentBoard.isCheck(color))
	{
		boolMovePutsTeamInCheck = true;
	}
	unmakeLastMove();
	return boolMovePutsTeamInCheck;
}

Game::Game(Player* white, Player* black)
{
	ptrWhitePlayer = white;
	ptrBlackPlayer = black;
}

Game::Game(int intGameID)
{

}

void Game::saveToDatabase() const
{

}

Player* Game::getWhitePlayer() const
{
	return ptrWhitePlayer;
}

Player* Game::getBlackPlayer() const
{
	return ptrBlackPlayer;
}

GameBoard Game::getCurrentBoard() const
{
	return currentBoard;
}

vector<Move> Game::getLegalMovesFrom(int intRow, int intCol)
{
	vector<Move> vecLegalMoves;
	for (int i = 0; i < GameBoard::NUM_OF_ROWS; i++)
	{
		for (int j = 0; j < GameBoard::NUM_OF_COLS; j++)
		{
			Move potentialMove(currentBoard.getSquare(intRow, intCol), currentBoard.getSquare(i, j));
			if (isMoveLegal(potentialMove))
			{
				vecLegalMoves.push_back(potentialMove);
			}
		}
	}
	return vecLegalMoves;
}

bool Game::isMoveLegal(Move potentialMove)
{
	if (currentBoard.isMovePossible(potentialMove))
	{
		PieceColor color = potentialMove.getInitialSquare().getPieceAtSquare()->getColor();
		return !doesMovePutTeamInCheck(potentialMove, color);
	}
	return false;
}

void Game::makeMove(Move aMove, bool boolTempMove)
{
	vecPreviousBoards.push_back(currentBoard);

	Square initialSquare = aMove.getInitialSquare();
	Square finalSquare = aMove.getFinalSquare();

	// Special case: castling queenside
	if (initialSquare.getPieceAtSquare()->getType() == KING && finalSquare.getCol() - initialSquare.getCol() == -2)
	{
		// Move the queenside rook from its initial square to the proper final square
		currentBoard.setPieceAt(finalSquare.getRow(), 3, currentBoard.getPieceAt(finalSquare.getRow(), 0));
		currentBoard.setPieceAt(finalSquare.getRow(), 0, nullptr);

		if (!boolTempMove)
		{
			// Update the column variable for the queenside rook
			currentBoard.getPieceAt(finalSquare.getRow(), 3)->setCurrentCol(3);

			// Update the hasBeenMoved status for the queenside rook
			Rook* queensideRook = dynamic_cast<Rook*>(currentBoard.getPieceAt(finalSquare.getRow(), 3));
			queensideRook->setHasBeenMoved(true);
		}
	}
	// Special case: castling kingside
	else if (initialSquare.getPieceAtSquare()->getType() == KING && finalSquare.getCol() - initialSquare.getCol() == 2)
	{
		// Move the kingside rook from its initial square to the proper final square
		currentBoard.setPieceAt(finalSquare.getRow(), 5, currentBoard.getPieceAt(finalSquare.getRow(), 7));
		currentBoard.setPieceAt(finalSquare.getRow(), 7, nullptr);

		if (!boolTempMove)
		{
			// Update the column variable for the kingside rook
			currentBoard.getPieceAt(finalSquare.getRow(), 5)->setCurrentCol(5);

			// Update the hasBeenMoved status for the kingside rook
			Rook* kingsideRook = dynamic_cast<Rook*>(currentBoard.getPieceAt(finalSquare.getRow(), 5));
			kingsideRook->setHasBeenMoved(true);
		}
	}

	// Classify the move as a pawn promotion move
	if (currentBoard.getPieceAt(initialSquare.getRow(), initialSquare.getCol())->getType() == PAWN &&
		(finalSquare.getRow() == 0 || finalSquare.getRow() == 7))
	{
		aMove.setIsPawnPromotionMove(true);
	}

	// Move the piece from the initial square to the final square
	currentBoard.setPieceAt(finalSquare.getRow(), finalSquare.getCol(), currentBoard.getPieceAt(initialSquare.getRow(), initialSquare.getCol()));
	currentBoard.setPieceAt(initialSquare.getRow(), initialSquare.getCol(), nullptr);

	if (!boolTempMove)
	{
		// Update its row and column variables
		currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol())->setCurrentRow(finalSquare.getRow());
		currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol())->setCurrentCol(finalSquare.getCol());
	}

	// Add the move to the list of previous moves
	vecPreviousMoves.push_back(aMove);

	// Remove the pawn captured via en passant
	if (currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol())->getType() == PAWN)
	{
		Pawn* pawn = dynamic_cast<Pawn*>(currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol()));
		if (pawn->getEnPassantCaptureSquare() != nullptr)
		{
			if (finalSquare.getRow() == pawn->getEnPassantCaptureSquare()->getRow() &&
				finalSquare.getCol() == pawn->getEnPassantCaptureSquare()->getCol())
			{
				int intVerticalMovement = finalSquare.getRow() - initialSquare.getRow();
				currentBoard.setPieceAt(pawn->getEnPassantCaptureSquare()->getRow() - intVerticalMovement, pawn->getEnPassantCaptureSquare()->getCol(), nullptr);
			}
		}
	}

	if (!boolTempMove)
	{
		// Reset the ability to capture en passant
		for (int i = 0; i < GameBoard::NUM_OF_ROWS; i++)
		{
			for (int j = 0; j < GameBoard::NUM_OF_COLS; j++)
			{
				if (currentBoard.getPieceAt(i, j) != nullptr)
				{
					if (currentBoard.getPieceAt(i, j)->getType() == PAWN)
					{
						Pawn* pawn = dynamic_cast<Pawn*>(currentBoard.getPieceAt(i, j));
						pawn->setEnPassantCaptureSquare(nullptr);
					}
				}
			}
		}

		// Determine if an en passant capture will be possible on the next move
		if (currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol())->getType() == PAWN)
		{
			if (abs(finalSquare.getRow() - initialSquare.getRow()) == 2)
			{
				Pawn* pawn = dynamic_cast<Pawn*>(currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol()));
				// See if there is an enemy pawn to the left
				Piece* pieceToTheLeft = currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol() - 1);
				if (pieceToTheLeft != nullptr)
				{
					if (pieceToTheLeft->getType() == PAWN && pieceToTheLeft->getColor() != pawn->getColor())
					{
						Pawn* enemyPawnToTheLeft = dynamic_cast<Pawn*>(pieceToTheLeft);
						int intDirectionMultiplier = finalSquare.getRow() - initialSquare.getRow() == 2 ? 1 : -1;
						Square* enPassantCaptureSquare = new Square(finalSquare.getRow() - intDirectionMultiplier, finalSquare.getCol(), currentBoard.getPieceAt(finalSquare.getRow() - intDirectionMultiplier, finalSquare.getCol()));
						enemyPawnToTheLeft->setEnPassantCaptureSquare(enPassantCaptureSquare);
					}
				}
				// See if there is an enemy pawn to the right
				Piece* pieceToTheRight = currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol() + 1);
				if (pieceToTheRight != nullptr)
				{
					if (pieceToTheRight->getType() == PAWN && pieceToTheRight->getColor() != pawn->getColor())
					{
						Pawn* enemyPawnToTheRight = dynamic_cast<Pawn*>(pieceToTheRight);
						int intDirectionMultiplier = finalSquare.getRow() - initialSquare.getRow() == 2 ? 1 : -1;
						Square* enPassantCaptureSquare = new Square(finalSquare.getRow() - intDirectionMultiplier, finalSquare.getCol(), currentBoard.getPieceAt(finalSquare.getRow() - intDirectionMultiplier, finalSquare.getCol()));
						enemyPawnToTheRight->setEnPassantCaptureSquare(enPassantCaptureSquare);
					}
				}
			}
		}

		// Adjust the hasBeenMoved status for kings and rooks
		if (currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol())->getType() == KING)
		{
			King* king = dynamic_cast<King*>(currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol()));
			king->setHasBeenMoved(true);
		}
		else if (currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol())->getType() == ROOK)
		{
			Rook* rook = dynamic_cast<Rook*>(currentBoard.getPieceAt(finalSquare.getRow(), finalSquare.getCol()));
			rook->setHasBeenMoved(true);
		}
	}
}

void Game::unmakeLastMove()
{
	currentBoard = vecPreviousBoards.back();
	vecPreviousBoards.pop_back();
	vecPreviousMoves.pop_back();
}

void Game::promotePawn(int intRow, int intCol, PieceType promotionType)
{
	PieceColor color = currentBoard.getPieceAt(intRow, intCol)->getColor();
	Piece* upgradedPiece;
	if (promotionType == QUEEN)
	{
		upgradedPiece = new Queen(color, intRow, intCol);
		currentBoard.setPieceAt(intRow, intCol, upgradedPiece);
	}
	else if (promotionType == KNIGHT)
	{
		upgradedPiece = new Knight(color, intRow, intCol);
		currentBoard.setPieceAt(intRow, intCol, upgradedPiece);
	}
	else if (promotionType == BISHOP)
	{
		upgradedPiece = new Bishop(color, intRow, intCol);
		currentBoard.setPieceAt(intRow, intCol, upgradedPiece);
	}
	else if (promotionType == ROOK)
	{
		upgradedPiece = new Rook(color, intRow, intCol);
		currentBoard.setPieceAt(intRow, intCol, upgradedPiece);
	}
	Move pawnPromotionMove = vecPreviousMoves.back();
	Square initialSquare = pawnPromotionMove.getInitialSquare();
	Move move(Square(initialSquare.getRow(), initialSquare.getCol(), upgradedPiece), pawnPromotionMove.getFinalSquare());
	move.setIsPawnPromotionMove(true);
	vecPreviousMoves.pop_back();
	vecPreviousMoves.push_back(move);
}

Move Game::getPreviousMove() const
{
	return vecPreviousMoves.back();
}

vector<string> Game::getPGNStrings() const
{

}

vector<Piece*> Game::getCapturedPieces() const
{
	vector<Piece*> vecCapturedPieces;
	for (Move aMove : vecPreviousMoves)
	{
		if (aMove.getFinalSquare().getPieceAtSquare() != nullptr)
		{
			vecCapturedPieces.push_back(aMove.getFinalSquare().getPieceAtSquare());
		}
		// En passant capture
		else if (aMove.getInitialSquare().getPieceAtSquare()->getType() == PAWN)
		{
			if (abs(aMove.getFinalSquare().getRow() - aMove.getInitialSquare().getRow()) == 1 &&
				abs(aMove.getFinalSquare().getCol() - aMove.getInitialSquare().getCol()) == 1)
			{
				PieceColor opponentColor = aMove.getInitialSquare().getPieceAtSquare()->getColor() == WHITE ? BLACK : WHITE;
				int intVerticalMovement = aMove.getFinalSquare().getRow() - aMove.getInitialSquare().getRow();
				vecCapturedPieces.push_back(new Pawn(opponentColor, aMove.getFinalSquare().getRow() - intVerticalMovement, aMove.getFinalSquare().getCol()));
			}
		}
	}
	return vecCapturedPieces;
}

bool Game::isCheckmate(PieceColor color)
{

}

bool Game::isStalemate(PieceColor color)
{

}