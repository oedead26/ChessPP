// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "MoveHistoryWidget.h"
#include <QLabel>
#include <QTableWidgetItem>
#include <QVBoxLayout>
using namespace std;

MoveHistoryWidget::MoveHistoryWidget()
{
    setWindowTitle("Move History");
    QVBoxLayout* layout = new QVBoxLayout;
    QLabel* titleLabel = new QLabel("<center><b>Move History</b></center>");
    layout->addWidget(titleLabel);
    tableWidget = new QTableWidget;
    tableWidget->setColumnCount(2);
    tableWidget->setColumnWidth(0, 120);
    tableWidget->setColumnWidth(1, 120);
    QList<QString> listOfHorizontalHeaderLabels;
    listOfHorizontalHeaderLabels.push_back("White");
    listOfHorizontalHeaderLabels.push_back("Black");
    tableWidget->setHorizontalHeaderLabels(QStringList(listOfHorizontalHeaderLabels));
    tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    layout->addWidget(tableWidget);
    setLayout(layout);
}

void MoveHistoryWidget::updateTable(vector<string> vecMovesAsStrings)
{
    if (vecMovesAsStrings.size() > 0)
    {
        tableWidget->setRowCount(static_cast<int>(vecMovesAsStrings.size() / 2 + vecMovesAsStrings.size() % 2));
    }
    else
    {
        tableWidget->setRowCount(1);
    }

    int intRowNumber = 0;
    int intMoveIndex = 0;
    while (intMoveIndex < vecMovesAsStrings.size())
    {
        QTableWidgetItem* playerWhiteMove = new QTableWidgetItem(QString::fromStdString(vecMovesAsStrings.at(intMoveIndex)));
        playerWhiteMove->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        tableWidget->setItem(intRowNumber, 0, playerWhiteMove);
        intMoveIndex++;

        if (intMoveIndex < vecMovesAsStrings.size())
        {
            QTableWidgetItem* playerBlackMove = new QTableWidgetItem(QString::fromStdString(vecMovesAsStrings.at(intMoveIndex)));
            playerBlackMove->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            tableWidget->setItem(intRowNumber, 1, playerBlackMove);
            intMoveIndex++;
        }

        intRowNumber++;
    }
    tableWidget->scrollToBottom();
}
