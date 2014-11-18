// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef CAPTUREDPIECESWIDGET_H
#define CAPTUREDPIECESWIDGET_H

#include "Piece.h"
#include <vector>
#include <QLabel>
#include <QWidget>
using namespace std;

class CapturedPiecesWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel* capturedPieces[6][5];
public:
    CapturedPiecesWidget();
    void updateCapturedPieces(vector<Piece*> vecCapturedPieces);
    string getImagePath(Piece* ptrPiece) const;
};

#endif
