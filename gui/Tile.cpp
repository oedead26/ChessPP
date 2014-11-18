// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "Tile.h"
using namespace std;

Tile::Tile(int row, int col)
{
    intRow = row;
    intCol = col;
}

void Tile::mousePressEvent(QMouseEvent*)
{
    emit clicked(intRow, intCol);
}
