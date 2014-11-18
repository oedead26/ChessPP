// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef PAWNPROMOTIONDIALOG_H
#define PAWNPROMOTIONDIALOG_H

#include "Piece.h"
#include <QCloseEvent>
#include <QDialog>
#include <QPushButton>
using namespace std;

class PawnPromotionDialog : public QDialog
{
    Q_OBJECT
private:
    PieceType selectedPieceType;
    QPushButton* queenButton;
    QPushButton* knightButton;
    QPushButton* bishopButton;
    QPushButton* rookButton;
public:
    PawnPromotionDialog(PieceColor color);
    PieceType getSelectedPieceType() const;
    void closeEvent(QCloseEvent* event);
private slots:
    void queenButtonHandler();
    void knightButtonHandler();
    void bishopButtonHandler();
    void rookButtonHandler();
};

#endif
