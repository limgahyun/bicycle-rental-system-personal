#ifndef SIGNUP_CONTROLLER_H
#define SIGNUP_CONTROLLER_H

#include <string>
#include <vector>
#include "Member.h"

using namespace std;

/*
    class: SignUpController
    description: 회원가입 기능을 제어하는 control 클래스
*/
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