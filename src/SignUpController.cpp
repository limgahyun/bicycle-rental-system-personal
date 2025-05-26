#include "SignUpController.h"

SignUpController::SignUpController() {}

bool SignUpController::isDuplicated(string id) {
    return UserCollection::getInstance()->findMemberById(id) != nullptr;
}

void SignUpController::addNewMember(string id, string password, string phoneNumber) {
    Member* newMember = new Member(id, password, phoneNumber);
    UserCollection::getInstance()->addMember(newMember);
}