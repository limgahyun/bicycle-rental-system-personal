#include "SignUpController.h"

// Initialize static member
vector<Member> SignUpController::members;

SignUpController::SignUpController() {}

/*
    함수 이름 : SignUpController::isDuplicated()
    기능	  : 아이디 중복 체크
    전달 인자 : id - 체크할 사용자 아이디
    반환값    : 중복 여부
*/
bool SignUpController::isDuplicated(string id) {
    for (const auto& member : members) {
        if (member.findUserById(id)) {
            return true;
        }
    }
    return false;
}

/*
    함수 이름 : SignUpController::addNewMember()
    기능	  : 새로운 회원 추가
    전달 인자 : id - 사용자 아이디, password - 사용자 비밀번호, phoneNumber - 사용자 전화번호
    반환값    : 없음
*/
void SignUpController::addNewMember(string id, string password, string phoneNumber) {
    Member newMember(id, password, phoneNumber);
    members.push_back(newMember);
} 

/*
    함수 이름 : SignUpController::getMembers()
    기능	 : 저장된 멤버 반환
    전달 인자 : 없음
    반환값    : 저장된 멤버
*/
const vector<Member>& SignUpController::getMembers() {
    return members;
}