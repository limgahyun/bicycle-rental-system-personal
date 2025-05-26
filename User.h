#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

typedef enum {
    ADMIN,
    USER
} Role;

// User entity class 선언
class User {
private:
    string userId;
    string password;
    Role userRole;
    bool isLoggedIn;

public:
    User();
    User(string id, string password);
    bool findUserById(string id);
    bool checkPassword(string password);
    bool isDuplicted(string id);
    void setLoggedIn(bool status);
    bool getLoggedIn() const;
    string getId() const;
};

#endif