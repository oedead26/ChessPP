// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef SELECTBUTTON_H
#define SELECTBUTTON_H

#include <QPushButton>
using namespace std;

class SelectButton : public QPushButton
{
    Q_OBJECT
public:
    int intGameID;
    SelectButton(int gameID) : QPushButton("Select")
    {
        intGameID = gameID;
    }
    int getGameID() const
    {
        return intGameID;
    }
signals:
    void clicked(int gameID);
protected:
    void mousePressEvent(QMouseEvent*)
    {
        emit clicked(intGameID);
    }
};

#endif
