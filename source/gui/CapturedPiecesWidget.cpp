// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "CapturedPiecesWidget.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
using namespace std;

CapturedPiecesWidget::CapturedPiecesWidget()
{
    setWindowTitle("Captured Pieces");
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* titleLabel = new QLabel("<center><b>Captured Pieces</b></center>");
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);
    for (int i = 0; i < 6; i++)
    {
        QHBoxLayout* rowLayout = new QHBoxLayout;
        for (int j = 0; j < 5; j++)
        {
            capturedPieces[i][j] = new QLabel;
            rowLayout->addWidget(capturedPieces[i][j]);
        }
        layout->addLayout(rowLayout);
    }
    setMinimumHeight(200);
    setLayout(layout);
}

void CapturedPiecesWidget::updateCapturedPieces(vector<Piece*> vecCapturedPieces)
{
    vector<Piece*> vecSortedCapturedPieces;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < vecCapturedPieces.size(); j++)
        {
            Piece* piece = vecCapturedPieces.at(j);
            if (piece->getType() == i / 2 && piece->getColor() == i % 2)
            {
                vecSortedCapturedPieces.push_back(piece);
            }
        }
    }

    int intRowIndex = 0;
    int intColumnIndex = 0;
    for (Piece* ptrPiece : vecSortedCapturedPieces)
    {
        QImage image(getImagePath(ptrPiece).c_str());
        image = image.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        capturedPieces[intRowIndex][intColumnIndex]->setPixmap(QPixmap::fromImage(image));
        if (intColumnIndex < 4)
        {
            intColumnIndex++;
        }
        else
        {
            intColumnIndex = 0;
            intRowIndex++;
        }
    }
}

string CapturedPiecesWidget::getImagePath(Piece* ptrPiece) const
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
