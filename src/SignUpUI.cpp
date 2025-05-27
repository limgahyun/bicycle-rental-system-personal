#include "SignUpUI.h"
#include <sstream>

SignUpUI::SignUpUI(ofstream& outFile) : outputFile(outFile) {}

void SignUpUI::requestSignUp(string input) {
    string id, password, phoneNumber;
    istringstream inputStringStream(input);
    
    // id, password, phoneNumber 추출
    inputStringStream >> id >> password >> phoneNumber;

    outputFile << "1.1. 회원가입" << endl;

    if (signUpController->addNewMember(id, password, phoneNumber)) {    
        outputFile << "> " << id << " " << password << " " << phoneNumber << endl << endl;
    } else {
        outputFile << "> " << "signup failed" << endl << endl;
    }
} 