#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class Database
{
public:
    Database();
    void connectToDatabase();
private:
    static QSqlDatabase db;
};

#endif // DATABASE_H
