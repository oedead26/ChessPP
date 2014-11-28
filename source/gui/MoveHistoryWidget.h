// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef MOVEHISTORYWIDGET_H
#define MOVEHISTORYWIDGET_H

#include <string>
#include <vector>
#include <QTableWidget>
#include <QWidget>
using namespace std;

class MoveHistoryWidget : public QWidget
{
    Q_OBJECT
private:
    QTableWidget* tableWidget;
public:
    MoveHistoryWidget();
    void updateTable(vector<string> vecPGNStrings);
};

#endif
