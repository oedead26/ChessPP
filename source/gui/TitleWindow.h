// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>
using namespace std;

class TitleWindow : public QWidget
{
    Q_OBJECT
public:
    TitleWindow();
private slots:
    void newGameButtonHandler();
    void resumeGameButtonHandler();
};

#endif
