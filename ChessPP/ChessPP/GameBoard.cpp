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
	if (initialSquare.getRow() == finalSquare.getRow()) // Horizontal movement
	{
		int intMinimumCol = min(initialSquare.getCol(), finalSquare.getCol());
		int intMaximumCol = max(initialSquare.getCol(), finalSquare.getCol());
		for (int i = intMinimumCol + 1; i < intMaximumCol; i++)
		{
			if (getPieceAt(initialSquare.getRow(), i) != nullptr)
			{
				return true;
			}
		}
		return false;
	}
	else if (initialSquare.getCol() == finalSquare.getCol()) // Vertical movement
	{
		int intMinimumRow = min(initialSquare.getRow(), finalSquare.getRow());
		int intMaximumRow = max(initialSquare.getRow(), finalSquare.getRow());
		for (int i = intMinimumRow + 1; i < intMaximumRow; i++)
		{
			if (getPieceAt(i, initialSquare.getCol()) != nullptr)
			{
				return true;
			}
		}
		return false;
	}
	else if (abs(finalSquare.getRow() - initialSquare.getRow()) == abs(finalSquare.getCol() - initialSquare.getCol())) // Diagonal movement
	{
		int intSlope = (finalSquare.getRow() - initialSquare.getRow()) / (finalSquare.getCol() - initialSquare.getCol());
		int intMinimumRow = min(initialSquare.getRow(), finalSquare.getRow());
		int intMaximumRow = max(initialSquare.getRow(), finalSquare.getRow());
		int intMinimumCol = min(initialSquare.getCol(), finalSquare.getCol());
		int intMaximumCol = max(initialSquare.getCol(), finalSquare.getCol());
		for (int i = intMinimumRow + 1; i < intMaximumRow; i++)
		{
			int intNextCol = intSlope == 1 ? intMinimumCol + (i - intMinimumRow) : intMaximumCol - (i - intMinimumRow);
			if (getPieceAt(i, intNextCol) != nullptr)
			{
				return true;
			}
		}
		return false;
	}
	// Knight movement
	return false;
}

bool GameBoard::isTeamAttackingSquare(Square square, PieceColor color) const
{
	for (int i = 0; i < NUM_OF_ROWS; i++)
	{
		for (int j = 0; j < NUM_OF_COLS; j++)
		{
			Piece* potentialAttackingPiece = getPieceAt(i, j);
			if (potentialAttackingPiece != nullptr)
			{
				if (potentialAttackingPiece->getColor() == color)
				{
					if (isMovePossible(Move(getSquare(i, j), square)))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

GameBoard::GameBoard()
{
	for (int i = 0; i < NUM_OF_ROWS; i++)
	{
		for (int j = 0; j < NUM_OF_COLS; j++)
		{
			if (i == 0 || i == 7)
			{
				PieceColor color = i == 0 ? BLACK : WHITE;
				if (j == 0 || j == 7)
				{
					arrSquares[i][j] = Square(i, j, new Rook(color, i, j));
				}
				else if (j == 1 || j == 6)
				{
					arrSquares[i][j] = Square(i, j, new Knight(color, i, j));
				}
				else if (j == 2 || j == 5)
				{
					arrSquares[i][j] = Square(i, j, new Bishop(color, i, j));
				}
				else if (j == 3)
				{
					arrSquares[i][j] = Square(i, j, new Queen(color, i, j));
				}
				else if (j == 4)
				{
					arrSquares[i][j] = Square(i, j, new King(color, i, j));
				}
			}
			else if (i == 1 || i == 6)
			{
				PieceColor color = i == 1 ? BLACK : WHITE;
				arrSquares[i][j] = Square(i, j, new Pawn(color, i, j));
			}
			else
			{
				arrSquares[i][j] = Square(i, j, nullptr);
			}
		}
	}
}

void GameBoard::setPieceAt(int intRow, int intCol, Piece* ptrPiece)
{
	arrSquares[intRow][intCol].setPieceAtSquare(ptrPiece);
}

void GameBoard::promotePawn(int intRow, int intCol, PieceType promotionType)
{
	dynamic_cast<Pawn*>(arrSquares[intRow][intCol].getPieceAtSquare())->promoteTo(promotionType);
}

Square GameBoard::getSquare(int intRow, int intCol) const
{
	return arrSquares[intRow][intCol];
}

Piece* GameBoard::getPieceAt(int intRow, int intCol) const
{
	return arrSquares[intRow][intCol].getPieceAtSquare();
}

bool GameBoard::isMovePossible(Move potentialMove) const
{
	Square initialSquare = potentialMove.getInitialSquare();
	Square finalSquare = potentialMove.getFinalSquare();
	int intInitialRow = initialSquare.getRow();
	int intInitialCol = initialSquare.getCol();
	int intFinalRow = finalSquare.getRow();
	int intFinalCol = finalSquare.getCol();

	// See if the final square is "off the board"
	if (intFinalRow < 0 || intFinalRow > NUM_OF_ROWS - 1 || intFinalCol < 0 || intFinalCol > NUM_OF_COLS - 1)
	{
		return false;
	}

	// See if the move actually involves a piece
	Piece* pieceMakingMove = getSquare(intInitialRow, intInitialCol).getPieceAtSquare();
	if (pieceMakingMove == nullptr)
	{
		return false;
	}

	// Begin the process of move validation
	Piece* pieceAtFinalSquare = getSquare(intFinalRow, intFinalCol).getPieceAtSquare();
	bool boolIsFinalSquareOccupied = pieceAtFinalSquare != nullptr;
	if (pieceMakingMove->isCapableOfMovingTo(intFinalRow, intFinalCol, boolIsFinalSquareOccupied))
	{
		// The move is illegal if the final square contains a "friendly piece"
		if (pieceAtFinalSquare != nullptr)
		{
			if (pieceAtFinalSquare->getColor() == pieceMakingMove->getColor())
			{
				return false;
			}
		}

		// The move is illegal if there are any obstructions between the initial square and the final square
		if (isObstructionBetween(initialSquare, finalSquare))
		{
			return false;
		}

		if (pieceMakingMove->getType() == KING)
		{
			// Queenside Castling
			if (intFinalRow == intInitialRow && intFinalCol == intInitialCol - 2)
			{
				// The move is illegal if any of the squares between the king and
				// the queenside rook are occupied
				if (getPieceAt(intInitialRow, intInitialCol - 1) != nullptr ||
					getPieceAt(intInitialRow, intInitialCol - 2) != nullptr ||
					getPieceAt(intInitialRow, intInitialCol - 3) != nullptr)
				{
					return false;
				}

				// The move is illegal if either the king or queenside rook has moved
				PieceColor color = pieceMakingMove->getColor();
				int intInitialRankOfKing = color == WHITE ? 7 : 0;
				if (getPieceAt(intInitialRankOfKing, 0) == nullptr || getPieceAt(intInitialRankOfKing, 4) == nullptr)
				{
					return false;
				}
				else if (getPieceAt(intInitialRankOfKing, 0)->getColor() != color || getPieceAt(intInitialRankOfKing, 0)->getType() != ROOK ||
					getPieceAt(intInitialRankOfKing, 4)->getColor() != color || getPieceAt(intInitialRankOfKing, 4)->getType() != KING)
				{
					return false;
				}
				else if (dynamic_cast<Rook*>(getPieceAt(intInitialRankOfKing, 0))->getHasBeenMoved() ||
					dynamic_cast<King*>(getPieceAt(intInitialRankOfKing, 4))->getHasBeenMoved())
				{
					return false;
				}

				// The move is illegal if the team making the move is currently in check
				if (isCheck(color))
				{
					return false;
				}

				PieceColor opponentColor = color == WHITE ? BLACK : WHITE;
				// The move is illegal if the opponent is attacking the square that the king would pass through
				if (isTeamAttackingSquare(getSquare(intInitialRow, intInitialCol - 1), opponentColor))
				{
					return false;
				}
			}
			// Kingside Castling
			else if (intFinalRow == intInitialRow && intFinalCol == intInitialCol + 2)
			{
				// The move is illegal if any of the squares between the king and
				// the kingside rook are occupied
				if (getPieceAt(intInitialRow, intInitialCol + 1) != nullptr ||
					getPieceAt(intInitialRow, intInitialCol + 2) != nullptr)
				{
					return false;
				}

				// The move is illegal if either the king or kingside rook has moved
				PieceColor color = pieceMakingMove->getColor();
				int intInitialRankOfKing = color == WHITE ? 7 : 0;
				if (getPieceAt(intInitialRankOfKing, 7) == nullptr || getPieceAt(intInitialRankOfKing, 4) == nullptr)
				{
					return false;
				}
				else if (getPieceAt(intInitialRankOfKing, 7)->getColor() != color || getPieceAt(intInitialRankOfKing, 7)->getType() != ROOK ||
					getPieceAt(intInitialRankOfKing, 4)->getColor() != color || getPieceAt(intInitialRankOfKing, 4)->getType() != KING)
				{
					return false;
				}
				else if (dynamic_cast<Rook*>(getPieceAt(intInitialRankOfKing, 7))->getHasBeenMoved() ||
					dynamic_cast<King*>(getPieceAt(intInitialRankOfKing, 4))->getHasBeenMoved())
				{
					return false;
				}

				// The move is illegal if the team making the move is currently in check
				if (isCheck(color))
				{
					return false;
				}

				PieceColor opponentColor = color == WHITE ? BLACK : WHITE;
				// The move is illegal if the opponent is attacking the square that the king would pass through
				if (isTeamAttackingSquare(getSquare(intInitialRow, intInitialCol + 1), opponentColor))
				{
					return false;
				}
			}
		}

		return true;
	}
	return false;
}

bool GameBoard::isCheck(PieceColor color) const
{

}