// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "GameSelectionDialog.h"
#include "GameWindow.h"
#include "SelectButton.h"
#include <QHBoxLayout>
#include <QHeaderView>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QVBoxLayout>
using namespace std;

GameSelectionDialog::GameSelectionDialog()
{
    setWindowTitle("Select Game");

    databaseManager = new DatabaseManager;
    databaseManager->connectToDatabase();
    tableModel = new CustomTableModel(this);
    tableModel->setQuery(QString("SELECT GameID,Date,Time,PlayerWhiteName,PlayerBlackName FROM Games ORDER BY Date DESC, TIME DESC"), databaseManager->getDatabase());
    tableModel->insertColumn(0);
    tableModel->setHeaderData(0, Qt::Horizontal, "");
    tableModel->setHeaderData(3, Qt::Horizontal, "White");
    tableModel->setHeaderData(4, Qt::Horizontal, "Black");
    tableView = new QTableView;
    tableView->setModel(tableModel);
    tableView->horizontalHeader()->setStyleSheet("QHeaderView { color:rgb(0,127,255); }");

    int intNumOfRows = tableModel->rowCount();
    for (int i = 0; i < intNumOfRows; i++)
    {
        int intGameID = tableModel->record(i).value(1).toString().toInt();
        SelectButton* selectButton = new SelectButton(intGameID);
        tableView->setIndexWidget(tableView->model()->index(i, 0), selectButton);
        QObject::connect(selectButton, SIGNAL(clicked(int)), this, SLOT(selectButtonHandler(int)));
    }
    tableModel->removeColumn(1);

    QLabel* playerFilterLabel = new QLabel("Filter by player:");
    playerFilterLineEdit = new QLineEdit;
    QPushButton* playerFilterButton = new QPushButton("Filter");
    QObject::connect(playerFilterButton, SIGNAL(clicked()), this, SLOT(filterButtonHandler()));
    QHBoxLayout* playerFilterLayout = new QHBoxLayout;
    playerFilterLayout->addWidget(playerFilterLabel);
    playerFilterLayout->addWidget(playerFilterLineEdit);
    playerFilterLayout->addWidget(playerFilterButton);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(tableView);
    layout->addLayout(playerFilterLayout);
    setMinimumWidth(tableView->width() - 83);
    setLayout(layout);
}

void GameSelectionDialog::selectButtonHandler(int intGameID)
{
    databaseManager->disconnectFromDatabase();
    close();
    GameWindow* gameWindow = new GameWindow(intGameID);
    gameWindow->move(500, 0);
    gameWindow->show();
}

void GameSelectionDialog::filterButtonHandler()
{
    string strQuery;
    string strPlayerName = playerFilterLineEdit->text().toStdString();
    if (strPlayerName == "")
    {
        strQuery = "SELECT GameID,Date,Time,PlayerWhiteName,PlayerBlackName FROM Games ORDER BY Date DESC, Time DESC";
    }
    else
    {
        strQuery = "SELECT GameID,Date,Time,PlayerWhiteName,PlayerBlackName FROM Games WHERE PlayerWhiteName='" + strPlayerName + "'" +
                " OR PlayerBlackName='" + strPlayerName + "' ORDER BY Date DESC";
    }
    tableModel->setQuery(QString::fromStdString(strQuery), databaseManager->getDatabase());
    tableModel->insertColumn(0);
    tableModel->setHeaderData(0, Qt::Horizontal, "");
    tableModel->setHeaderData(3, Qt::Horizontal, "White");
    tableModel->setHeaderData(4, Qt::Horizontal, "Black");

    int intNumOfRows = tableModel->rowCount();
    for (int i = 0; i < intNumOfRows; i++)
    {
        int intGameID = tableModel->record(i).value(1).toString().toInt();
        SelectButton* selectButton = new SelectButton(intGameID);
        tableView->setIndexWidget(tableView->model()->index(i, 0), selectButton);
        QObject::connect(selectButton, SIGNAL(clicked(int)), this, SLOT(selectButtonHandler(int)));
    }
    tableModel->removeColumn(1);
}
