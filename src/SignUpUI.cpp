#include "SignUpUI.h"
#include <sstream>

SignUpUI::SignUpUI(ofstream& outputFile) : outputFile(outputFile) {
    signUpController = new SignUpController();
}

void SignUpUI::requestSignUp(string input) {
    string id, password, phoneNumber;
    istringstream iss(input);
    
    // id, password, phoneNumber 추출
    iss >> id >> password >> phoneNumber;

    if (!signUpController->isDuplicated(id)) {
        signUpController->addNewMember(id, password, phoneNumber);
        outputFile << "1.1. 회원가입" << endl;
        outputFile << "> " << id << " " << password << " " << phoneNumber << endl;
    } else {
        outputFile << "1.1. 회원가입" << endl;
        outputFile << "> " << "Error: ID already exists" << endl;
    }
} 