// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QLabel>
#include <QPushButton>
using namespace std;

class TitleWindow : public QWidget
{
    Q_OBJECT
private:
    QLabel* titleLabel;
    QLabel* createdByLabel;
    QLabel* imageLabel;
    QPushButton* newGameButton;
    QPushButton* resumeGameButton;
public:
    TitleWindow();
private slots:
    void newGameButtonHandler();
    void resumeGameButtonHandler();
};

#endif
