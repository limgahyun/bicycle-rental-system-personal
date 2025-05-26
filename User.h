#ifndef USER_H
#define USER_H

#include <string>

// User entity class 선언
class User {
private:
    std::string id;
    std::string password;
    bool isLoggedIn;

public:
    User();
    User(std::string id, std::string password);
    bool findUserById(std::string id);
    bool checkPassword(std::string password);
    void setLoggedIn(bool status);
    bool getLoggedIn() const;
    std::string getId() const;
};

#endif // USER_H 