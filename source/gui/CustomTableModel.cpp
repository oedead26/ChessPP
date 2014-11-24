// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "CustomTableModel.h"
using namespace std;

QVariant CustomTableModel::data(const QModelIndex &index, int intRole) const
{
    if (intRole == Qt::DisplayRole)
    {
        return QSqlQueryModel::data(index, intRole);
    }
    else if (intRole == Qt::TextAlignmentRole)
    {
        return Qt::AlignCenter;
    }
    return QVariant();
}
