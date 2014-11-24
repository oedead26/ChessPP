// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "GameWindow.h"
#include "PawnPromotionDialog.h"
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QVBoxLayout>
using namespace std;

void GameWindow::setupGUI()
{
    QImage windowIconImage(":/images/program_icon.png");
    setWindowIcon(QIcon(QPixmap::fromImage(windowIconImage)));
    setWindowTitle("Chess++");

    string arrRankLabels[8] = { "8", "7", "6", "5", "4", "3", "2", "1" };
    QVBoxLayout* rankLabelsLayout = new QVBoxLayout;
    for (int i = 0; i < 8; i++)
    {
        QLabel* rankLabel = new QLabel(QString::fromStdString("<b>" + arrRankLabels[i] + "</b>"));
        rankLabel->setAlignment(Qt::AlignCenter);
        rankLabel->setMinimumWidth(15);
        rankLabel->setMinimumHeight(100);
        rankLabelsLayout->addWidget(rankLabel);
    }

    QVBoxLayout* boardLayout = new QVBoxLayout;
    for (int i = 0; i < GameBoard::NUM_OF_ROWS; i++)
    {
        QHBoxLayout* rowLayout = new QHBoxLayout;
        for (int j = 0; j < GameBoard::NUM_OF_COLS; j++)
        {
            arrTiles[i][j] = new Tile(i, j);
            arrTiles[i][j]->setMinimumWidth(100);
            arrTiles[i][j]->setMinimumHeight(100);
            QObject::connect(arrTiles[i][j], SIGNAL(clicked(int, int)), this, SLOT(tileHandler(int,int)));
            rowLayout->addWidget(arrTiles[i][j]);
        }
        boardLayout->addLayout(rowLayout);
    }

    QHBoxLayout* leftLayout = new QHBoxLayout;
    leftLayout->addLayout(rankLabelsLayout);
    leftLayout->addLayout(boardLayout);

    string arrFileLabels[8] = { "a", "b", "c", "d", "e", "f", "g", "h" };
    QHBoxLayout* fileLabelsLayout = new QHBoxLayout;
    QLabel* spacerLabel = new QLabel;
    spacerLabel->setMinimumWidth(15);
    spacerLabel->setMinimumHeight(15);
    fileLabelsLayout->addWidget(spacerLabel);
    for (int i = 0; i < 8; i++)
    {
        QLabel* fileLabel = new QLabel("<b>" + QString::fromStdString(arrFileLabels[i]) + "</b>");
        fileLabel->setAlignment(Qt::AlignCenter);
        fileLabel->setMinimumWidth(100);
        fileLabel->setMinimumHeight(15);
        fileLabelsLayout->addWidget(fileLabel);
    }

    QVBoxLayout* leftPanelLayout = new QVBoxLayout;
    leftPanelLayout->addLayout(leftLayout);
    leftPanelLayout->addLayout(fileLabelsLayout);

    QVBoxLayout* rightPanelLayout = new QVBoxLayout;
    saveGameButton = new QPushButton("Save Game");
    QObject::connect(saveGameButton, SIGNAL(clicked()), this, SLOT(saveGameButtonHandler()));
    rightPanelLayout->addWidget(saveGameButton);
    moveHistoryWidget = new MoveHistoryWidget;
    moveHistoryWidget->updateTable(ptrGame->getMovesAsStrings());
    rightPanelLayout->addWidget(moveHistoryWidget);
    capturedPiecesWidget = new CapturedPiecesWidget;
    capturedPiecesWidget->updateCapturedPieces(ptrGame->getCapturedPieces());
    rightPanelLayout->addWidget(capturedPiecesWidget);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addLayout(leftPanelLayout);
    layout->addLayout(rightPanelLayout);

    setLayout(layout);
    updateGameBoard();
}

void GameWindow::updateGameBoard()
{
    for (int i = 0; i < GameBoard::NUM_OF_ROWS; i++)
    {
        for (int j = 0; j < GameBoard::NUM_OF_COLS; j++)
        {
            bool boolHasTileBeenColored = false;
            Move* previousMove = ptrGame->getPreviousMove();
            if (previousMove != nullptr)
            {
                if ((previousMove->getInitialSquare().getRow() == i && previousMove->getInitialSquare().getCol() == j) ||
                    (previousMove->getFinalSquare().getRow() == i && previousMove->getFinalSquare().getCol() == j))
                {
                    arrTiles[i][j]->setStyleSheet("background:rgb(255,0,0);");
                    boolHasTileBeenColored = true;
                }
            }
            if (!boolHasTileBeenColored)
            {
                if ((i + j) % 2 == 0)
                {
                    arrTiles[i][j]->setStyleSheet("background:rgb(255,255,255);");
                }
                else
                {
                    arrTiles[i][j]->setStyleSheet("background:rgb(0,127,255);");
                }
            }
            Piece* ptrPiece = ptrGame->getCurrentBoard().getPieceAt(i, j);
            if (ptrPiece != nullptr)
            {
                QImage image(getImagePath(ptrPiece).c_str());
                arrTiles[i][j]->setPixmap(QPixmap::fromImage(image));
            }
            else
            {
                arrTiles[i][j]->clear();
            }
        }
    }
}

string GameWindow::getImagePath(Piece* ptrPiece) const
{
    string strColor = ptrPiece->getColor() == WHITE ? "WHITE" : "BLACK";
    string strType;
    if (ptrPiece->getType() == PAWN)
    {
        strType = "PAWN";
    }
    else if (ptrPiece->getType() == KNIGHT)
    {
        strType = "KNIGHT";
    }
    else if (ptrPiece->getType() == BISHOP)
    {
        strType = "BISHOP";
    }
    else if (ptrPiece->getType() == ROOK)
    {
        strType = "ROOK";
    }
    else if (ptrPiece->getType() == QUEEN)
    {
        strType = "QUEEN";
    }
    else if (ptrPiece->getType() == KING)
    {
        strType = "KING";
    }
    return ":/images/" + strColor + "_" + strType + ".png";
}

GameWindow::GameWindow(string strWhitePlayerName, string strBlackPlayerName)
{
    colorToMove = WHITE;
    boolIsInitialClick = true;
    Player* whitePlayer = new Player(strWhitePlayerName, WHITE);
    Player* blackPlayer = new Player(strBlackPlayerName, BLACK);
    ptrGame = new Game(whitePlayer, blackPlayer);
    setupGUI();
}

GameWindow::GameWindow(int intGameID)
{
    ptrGame = new Game(intGameID);
    colorToMove = ptrGame->getMovesAsStrings().size() % 2 == 0 ? WHITE : BLACK;
    boolIsInitialClick = true;
    setupGUI();
}

void GameWindow::saveGameButtonHandler()
{
    ptrGame->saveToDatabase();
    QMessageBox* savedGameMessageBox = new QMessageBox;
    savedGameMessageBox->setWindowTitle("Chess++");
    savedGameMessageBox->setText("Game successfully saved!");
    savedGameMessageBox->show();
}

void GameWindow::tileHandler(int intRow, int intCol)
{
    if (!ptrGame->isCheckmate(colorToMove) && !ptrGame->isStalemate(colorToMove))
    {
        if (boolIsInitialClick)
        {
            initialSquare = ptrGame->getCurrentBoard().getSquare(intRow, intCol);
            if (initialSquare.getPieceAtSquare() != nullptr)
            {
                if (initialSquare.getPieceAtSquare()->getColor() == colorToMove)
                {
                    arrTiles[intRow][intCol]->setStyleSheet("background:rgb(0,255,0);");
                    vector<Move> vecLegalMoves = ptrGame->getLegalMovesFrom(intRow, intCol);
                    for (Move m : vecLegalMoves)
                    {
                        arrTiles[m.getFinalSquare().getRow()][m.getFinalSquare().getCol()]->setStyleSheet("background:rgb(255,255,0);");
                    }
                    boolIsInitialClick = false;
                }
            }
        }
        else
        {
            finalSquare = ptrGame->getCurrentBoard().getSquare(intRow, intCol);
            Move aMove(initialSquare, finalSquare);
            if (ptrGame->isMoveLegal(aMove))
            {
                ptrGame->makeMove(aMove);

                // Deal with pawn promotion
                Piece* ptrPieceAtFinalSquare = ptrGame->getCurrentBoard().getPieceAt(aMove.getFinalSquare().getRow(), aMove.getFinalSquare().getCol());
                if (ptrPieceAtFinalSquare->getType() == PAWN)
                {
                    if (aMove.getFinalSquare().getRow() == 0 || aMove.getFinalSquare().getRow() == 7)
                    {
                        PawnPromotionDialog* pawnPromotionDialog = new PawnPromotionDialog(ptrPieceAtFinalSquare->getColor());
                        pawnPromotionDialog->exec();
                        ptrGame->promotePawn(aMove.getFinalSquare().getRow(), aMove.getFinalSquare().getCol(), pawnPromotionDialog->getSelectedPieceType());
                    }
                }

                capturedPiecesWidget->updateCapturedPieces(ptrGame->getCapturedPieces());
                moveHistoryWidget->updateTable(ptrGame->getMovesAsStrings());

                colorToMove = colorToMove == WHITE ? BLACK : WHITE;
                if (ptrGame->isCheckmate(colorToMove) || ptrGame->isStalemate(colorToMove))
                {
                    saveGameButton->setEnabled(false);
                    QMessageBox* gameOverMessageBox = new QMessageBox;
                    gameOverMessageBox->setWindowTitle("Game Over!");
                    if (ptrGame->isCheckmate(ptrGame->getWhitePlayer()->getPieceColor()))
                    {
                        string strMessage = ptrGame->getWhitePlayer()->getName() + " (team WHITE) has been checkmated!";
                        gameOverMessageBox->setText(QString::fromStdString(strMessage));
                    }
                    else if (ptrGame->isCheckmate(ptrGame->getBlackPlayer()->getPieceColor()))
                    {
                        string strMessage = ptrGame->getBlackPlayer()->getName() + " (team BLACK) has been checkmated!";
                        gameOverMessageBox->setText(QString::fromStdString(strMessage));
                    }
                    else if (ptrGame->isStalemate(ptrGame->getWhitePlayer()->getPieceColor()) || ptrGame->isStalemate(ptrGame->getBlackPlayer()->getPieceColor()))
                    {
                        gameOverMessageBox->setText(QString("Stalemate!"));
                    }
                    gameOverMessageBox->show();
                }
            }
            updateGameBoard();
            if (!ptrGame->isCheckmate(colorToMove) && !ptrGame->isStalemate(colorToMove))
            {
                boolIsInitialClick = true;
            }
        }
    }
}
