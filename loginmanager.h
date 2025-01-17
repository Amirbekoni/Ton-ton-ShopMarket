#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H

#include <QString>

class LoginManager {
public:
    static void setLoggedInUser(const QString &userName);
    static QString getLoggedInUser();
    static bool isUserLoggedIn();

private:
    static QString loggedInUser;
};

#endif // LOGINMANAGER_H
