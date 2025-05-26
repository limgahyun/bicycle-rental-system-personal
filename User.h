#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

// User entity class 선언
class User {
private:
    string id;
    string password;
    bool isLoggedIn;

public:
    User();
    User(string id, string password);
    bool findUserById(string id);
    bool checkPassword(string password);
    void setLoggedIn(bool status);
    bool getLoggedIn() const;
    string getId() const;
};

#endif // USER_H 