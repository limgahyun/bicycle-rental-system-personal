#include "SignUpUI.h"
#include <sstream>

SignUpUI::SignUpUI(ofstream& outFile) : outputFile(outFile) {}

/*
    함수 이름 : SignUpUI::requestSignUp()
    기능	  : 회원가입 요청을 처리하고 결과를 출력
    전달 인자 : 입력 문자열
    반환값    : 없음
*/
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