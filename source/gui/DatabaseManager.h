// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <vector>
#include <QSqlDatabase>
using namespace std;

class DatabaseManager
{
private:
    QSqlDatabase db;
public:
    DatabaseManager();
    void connectToDatabase()
    {
        db.open();
    }
    void disconnectFromDatabase()
    {
        db.close();
    }
    void addGame(string strDate, string strTime, string strPlayerWhite, string strPlayerBlack, string strMovesString, string strPromotionsString) const;
    vector<string> getGame(int intGameID) const;
    QSqlDatabase getDatabase() const
    {
        return db;
    }
};

#endif
