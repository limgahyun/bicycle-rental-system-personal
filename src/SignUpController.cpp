#include "SignUpController.h"

// Initialize static member
vector<Member> SignUpController::members;

SignUpController::SignUpController() {}

bool SignUpController::isDuplicated(string id) {
    for (const auto& member : members) {
        if (member.findUserById(id)) {
            return true;
        }
    }
    return false;
}

void SignUpController::addNewMember(string id, string password, string phoneNumber) {
    Member newMember(id, password, phoneNumber);
    members.push_back(newMember);
} 