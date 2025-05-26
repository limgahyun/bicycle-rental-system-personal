#include "LoginUI.h"
#include <iostream>
#include <string>
#include <sstream>

LoginUI::LoginUI(ofstream& outputFile) : outputFile(outputFile) {
    loginController = new LoginController();
}

/*
	함수 이름 : LoginUI::requestLogin(string input)
	기능	 : id와 password를 추출하고, loginController에게 전달하여 로그인 여부를 확인한 후 결과 출력
	전달 인자 : 입력 문자열
	반환값    : 없음
*/
void LoginUI::requestLogin(string input) {
    string id, password;
    istringstream iss(input);
    
    // id, password 추출하기
    iss >> id >> password;

    outputFile << "2.1. 로그인" << endl;

    if (loginController->login(id, password)) {
        outputFile << "> " << id << " " << password << endl << endl;
    } else {
        outputFile << "> " << "login failed" << endl << endl;
    }
}