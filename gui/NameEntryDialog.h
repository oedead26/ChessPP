// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef NAMEENTRYDIALOG_H
#define NAMEENTRYDIALOG_H

#include <string>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
using namespace std;

class NameEntryDialog : public QDialog
{
    Q_OBJECT
private:
    QLabel* instructionsLabel;
    QLabel* whitePlayerLabel;
    QLabel* blackPlayerLabel;
    QLineEdit* whitePlayerLineEdit;
    QLineEdit* blackPlayerLineEdit;
    QPushButton* okButton;
    QPushButton* backButton;
    string strWhitePlayerName;
    string strBlackPlayerName;
public:
    NameEntryDialog(QWidget* parent);
    string getWhitePlayerName() const;
    string getBlackPlayerName() const;
private slots:
    void okButtonHandler();
    void backButtonHandler();
};

#endif
