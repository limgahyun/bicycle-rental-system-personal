#include "SignUpUI.h"
#include <sstream>

SignUpUI::SignUpUI(ofstream& outFile) : outputFile(outFile) {}

void SignUpUI::requestSignUp(string input) {
    string id, password, phoneNumber;
    istringstream inputStringStream(input);
    
    // id, password, phoneNumber 추출
    inputStringStream >> id >> password >> phoneNumber;

    if (!signUpController->isDuplicated(id)) {
        signUpController->addNewMember(id, password, phoneNumber);
        outputFile << "1.1. 회원가입" << endl;
        outputFile << "> " << id << " " << password << " " << phoneNumber << endl;
    } else {
        outputFile << "1.1. 회원가입" << endl;
        outputFile << "> " << "signup failed" << endl;
    }
} 