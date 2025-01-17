#include "database.h"

Database::Database() {}

void Database::connectToDatabase() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        qDebug() << "Database connection already exists!";
        return;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("ShopMarket");
    db.setUserName("postgres");
    db.setPassword("postgres");
    db.setPort(5432);

    if (!db.open()) {
        qDebug() << "Error connecting to DB:" << db.lastError().text();
    } else {
        qDebug() << "Database connection successful!";
    }
}
