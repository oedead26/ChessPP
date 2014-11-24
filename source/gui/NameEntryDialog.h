// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef NAMEENTRYDIALOG_H
#define NAMEENTRYDIALOG_H

#include <string>
#include <QDialog>
#include <QLineEdit>
using namespace std;

class NameEntryDialog : public QDialog
{
    Q_OBJECT
private:
    QLineEdit* whitePlayerLineEdit;
    QLineEdit* blackPlayerLineEdit;
    string strWhitePlayerName;
    string strBlackPlayerName;
public:
    NameEntryDialog(QWidget* parent);
    string getWhitePlayerName() const
    {
        return strWhitePlayerName;
    }
    string getBlackPlayerName() const
    {
        return strBlackPlayerName;
    }
private slots:
    void okButtonHandler();
    void backButtonHandler();
};

#endif
