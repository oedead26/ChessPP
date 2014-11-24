// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef PAWNPROMOTIONDIALOG_H
#define PAWNPROMOTIONDIALOG_H

#include "Piece.h"
#include <QCloseEvent>
#include <QDialog>
using namespace std;

class PawnPromotionDialog : public QDialog
{
    Q_OBJECT
private:
    PieceType selectedPieceType;
public:
    PawnPromotionDialog(PieceColor color);
    PieceType getSelectedPieceType() const
    {
        return selectedPieceType;
    }
    void closeEvent(QCloseEvent* event)
    {
        selectedPieceType == PAWN ? event->ignore() : event->accept();
    }
private slots:
    void queenButtonHandler();
    void knightButtonHandler();
    void bishopButtonHandler();
    void rookButtonHandler();
};

#endif
