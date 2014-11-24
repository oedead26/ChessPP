// Aaron Oeder, Jacob Owens, and Trevor Berceau
// CS 371 Final Project: Chess++
#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
using namespace std;

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("SavedGames.db");
}

void DatabaseManager::addGame(string strDate, string strTime, string strPlayerWhite, string strPlayerBlack, string strMovesString, string strPromotionsString) const
{
    QSqlQuery query;
    query.exec(QString::fromStdString("INSERT INTO Games(GameID,Date,Time,PlayerWhiteName,PlayerBlackName,MovesString,PromotionsString) "
               "VALUES(null,'" + strDate + "','" + strTime + "','" + strPlayerWhite + "','" + strPlayerBlack + "','" + strMovesString + "','" + strPromotionsString + "')"));
}

vector<string> DatabaseManager::getGame(int intGameID) const
{
    QSqlQuery query(QString::fromStdString("SELECT * FROM Games WHERE GameID=" + to_string(intGameID)));
    vector<string> vecGame;
    while (query.next())
    {
        for (int i = 0; i < db.record("Games").count(); i++)
        {
            vecGame.push_back(query.value(i).toString().toStdString());
        }
    }
    return vecGame;
}
