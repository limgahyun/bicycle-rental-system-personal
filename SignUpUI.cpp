#include "SignUpUI.h"
#include <sstream>

SignUpUI::SignUpUI(ofstream& out_fp) : out_fp(out_fp) {
    signUpController = new SignUpController();
}

void SignUpUI::requestSignUp(string input) {
    string id, password, phoneNumber;
    istringstream iss(input);
    
    // id, password, phoneNumber 추출
    iss >> id >> password >> phoneNumber;
    
    // [] 제거
    id = (id[0] == '[') ? id.substr(1, id.length()-2) : id;
    password = (password[0] == '[') ? password.substr(1, password.length()-2) : password;
    phoneNumber = (phoneNumber[0] == '[') ? phoneNumber.substr(1, phoneNumber.length()-2) : phoneNumber;

    if (!signUpController->isDuplicated(id)) {
        signUpController->addNewMember(id, password, phoneNumber);
        out_fp << "1.1. 회원가입" << endl;
        out_fp << "> " << id << " " << password << " " << phoneNumber << endl;
    } else {
        out_fp << "1.1. 회원가입" << endl;
        out_fp << "> " << "Error: ID already exists" << endl;
    }
} 