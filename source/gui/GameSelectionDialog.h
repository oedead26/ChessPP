// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef GAMESELECTIONDIALOG_H
#define GAMESELECTIONDIALOG_H

#include "CustomTableModel.h"
#include "DatabaseManager.h"
#include <QDialog>
#include <QLineEdit>
#include <QTableView>
using namespace std;

class GameSelectionDialog : public QDialog
{
    Q_OBJECT
private:
    DatabaseManager* databaseManager;
    CustomTableModel* tableModel;
    QTableView* tableView;
    QLineEdit* playerFilterLineEdit;
public:
    GameSelectionDialog();
private slots:
    void selectButtonHandler(int intGameID);
    void filterButtonHandler();
};

#endif
