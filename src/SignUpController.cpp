#include "SignUpController.h"

SignUpController::SignUpController() {}

/*
    함수 이름 : SignUpController::addNewMember()
    기능	  : 새로운 회원 추가
    전달 인자 : id - 사용자 아이디, password - 사용자 비밀번호, phoneNumber - 사용자 전화번호
    반환값    : 회원 추가 성공 여부
*/
bool SignUpController::addNewMember(string id, string password, string phoneNumber) {
    UserCollection* userCollection = UserCollection::getInstance();
    if (userCollection->findMemberById(id) == nullptr) {
        return false;
    }

    Member* newMember = new Member(id, password, phoneNumber);
    userCollection->addMember(newMember);
    return true;
}