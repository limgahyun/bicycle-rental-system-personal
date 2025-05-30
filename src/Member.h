#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include "User.h"

using namespace std;

/*
    class: Member
    description: 회원 클래스
*/
class Member : public User {
private:
    string phoneNumber;

public:
    Member(string id, string password, string phoneNumber);
};

#endif 