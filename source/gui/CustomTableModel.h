// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QSqlQueryModel>
using namespace std;

class CustomTableModel : public QSqlQueryModel
{
public:
    CustomTableModel(QObject* parent = 0) : QSqlQueryModel(parent) {}
    QVariant data(const QModelIndex &index, int intRole) const;
};

#endif
