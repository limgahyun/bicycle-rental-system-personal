#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

// role enum
typedef enum {
    ADMIN,
    USER
} Role;

/*
    class: User
    description: 사용자 클래스
*/
class User {
private:
    string userId;
    string password;
    Role userRole;
    bool isLoggedIn;

public:
    User();
    User(string id, string password);
    bool findUserById(string id) const;
    bool checkPassword(string password) const;
    void setLoggedIn(bool status);
    string getId() const;
};

#endif