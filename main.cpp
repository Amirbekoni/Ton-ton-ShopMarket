#include <QApplication>
#include "mainwindow.h"
#include "database.h"

Database globalDatabase;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Establish a single database connection
    globalDatabase.connectToDatabase();

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
