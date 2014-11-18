// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef TILE_H
#define TILE_H

#include <QLabel>
using namespace std;

class Tile : public QLabel
{
    Q_OBJECT
private:
    int intRow;
    int intCol;
public:
    Tile(int row, int col);
signals:
    void clicked(int row, int col);
protected:
    void mousePressEvent(QMouseEvent*);
};

#endif
