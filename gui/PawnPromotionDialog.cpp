// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "PawnPromotionDialog.h"
#include <QHBoxLayout>
#include <QSize>
#include <QVBoxLayout>
using namespace std;

PawnPromotionDialog::PawnPromotionDialog(PieceColor color)
{
    selectedPieceType = PAWN;

    setModal(true);

    QImage windowIconImage(":/images/program_icon.png");
    setWindowIcon(QIcon(QPixmap::fromImage(windowIconImage)));
    setWindowTitle("Pawn Promotion");

    string strPieceColor = color == WHITE ? "WHITE" : "BLACK";
    QSize buttonSize(125, 125);

    QHBoxLayout* topRowLayout = new QHBoxLayout;
    queenButton = new QPushButton();
    QObject::connect(queenButton, SIGNAL(clicked()), this, SLOT(queenButtonHandler()));
    queenButton->setFixedSize(buttonSize);
    string strQueenImagePath = ":/images/" + strPieceColor + "_QUEEN.png";
    QImage queenImage(strQueenImagePath.c_str());
    queenButton->setIcon(QIcon(QPixmap::fromImage(queenImage)));
    queenButton->setIconSize(buttonSize);
    knightButton = new QPushButton;
    QObject::connect(knightButton, SIGNAL(clicked()), this, SLOT(knightButtonHandler()));
    knightButton->setFixedSize(buttonSize);
    string strKnightImagePath = ":/images/" + strPieceColor + "_KNIGHT.png";
    QImage knightImage(strKnightImagePath.c_str());
    knightButton->setIcon(QIcon(QPixmap::fromImage(knightImage)));
    knightButton->setIconSize(buttonSize);
    topRowLayout->addWidget(queenButton);
    topRowLayout->addWidget(knightButton);

    QHBoxLayout* bottomRowLayout = new QHBoxLayout;
    bishopButton = new QPushButton;\
    QObject::connect(bishopButton, SIGNAL(clicked()), this, SLOT(bishopButtonHandler()));
    bishopButton->setFixedSize(buttonSize);
    bishopButton->setIconSize(buttonSize);
    string strBishopImagePath = ":/images/" + strPieceColor + "_BISHOP.png";
    QImage bishopImage(strBishopImagePath.c_str());
    bishopButton->setIcon(QIcon(QPixmap::fromImage(bishopImage)));
    rookButton = new QPushButton;
    QObject::connect(rookButton, SIGNAL(clicked()), this, SLOT(rookButtonHandler()));
    rookButton->setFixedSize(buttonSize);
    rookButton->setIconSize(buttonSize);
    string strRookImagePath = ":/images/" + strPieceColor + "_ROOK.png";
    QImage rookImage(strRookImagePath.c_str());
    rookButton->setIcon(QIcon(QPixmap::fromImage(rookImage)));
    bottomRowLayout->addWidget(bishopButton);
    bottomRowLayout->addWidget(rookButton);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(topRowLayout);
    layout->addLayout(bottomRowLayout);
    setLayout(layout);
}

PieceType PawnPromotionDialog::getSelectedPieceType() const
{
    return selectedPieceType;
}

void PawnPromotionDialog::closeEvent(QCloseEvent* event)
{
    selectedPieceType == PAWN ? event->ignore() : event->accept();
}

void PawnPromotionDialog::queenButtonHandler()
{
    selectedPieceType = QUEEN;
    close();
}

void PawnPromotionDialog::knightButtonHandler()
{
    selectedPieceType = KNIGHT;
    close();
}

void PawnPromotionDialog::bishopButtonHandler()
{
    selectedPieceType = BISHOP;
    close();
}

void PawnPromotionDialog::rookButtonHandler()
{
    selectedPieceType = ROOK;
    close();
}
