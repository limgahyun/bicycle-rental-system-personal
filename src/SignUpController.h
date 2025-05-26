#ifndef SIGNUP_CONTROLLER_H
#define SIGNUP_CONTROLLER_H

#include <string>
#include <vector>
#include "Member.h"

using namespace std;

class SignUpController {
private:
    static vector<Member> members;  // 저장된 멤버

public:
    SignUpController();
    bool isDuplicated(string id);
    void addNewMember(string id, string password, string phoneNumber);
    static vector<Member>& getMembers() { return members; }
};

#endif 