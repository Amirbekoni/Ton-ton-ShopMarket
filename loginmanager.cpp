#include "loginmanager.h"

QString LoginManager::loggedInUser = "";

void LoginManager::setLoggedInUser(const QString &userName) {
    loggedInUser = userName;
}

QString LoginManager::getLoggedInUser() {
    return loggedInUser;
}

bool LoginManager::isUserLoggedIn() {
    return !loggedInUser.isEmpty();
}
