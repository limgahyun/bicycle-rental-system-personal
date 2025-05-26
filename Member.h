#ifndef MEMBER_H
#define MEMBER_H

#include "User.h"
#include <string>

using namespace std;

class Member : public User {
private:
    string phoneNumber;

public:
    Member();
    Member(string id, string password, string phoneNumber);
    string getPhoneNumber() const;
};

#endif 