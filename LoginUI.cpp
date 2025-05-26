#include "LoginUI.h"
#include <iostream>
#include <string>
#include <sstream>

LoginUI::LoginUI(std::ofstream& out_fp) : out_fp(out_fp) {
    loginController = new LoginController();
}

/*
	함수 이름 : LoginUI::requestLogin(std::string input)
	기능	  : id와 password를 추출하고, loginController에게 전달하여 로그인 여부를 확인한 후 결과 출력
	전달 인자 : 입력 문자열
	반환값    : 없음
*/
void LoginUI::requestLogin(std::string input) {
    std::string id, password;
    std::istringstream iss(input);
    
    // id, password 추출하기
    iss >> id >> password;
    
    // [] 제거하기
    id = (id[0] == '[') ? id.substr(1, id.length()-2) : id;
    password = (password[0] == '[') ? password.substr(1, password.length()-2) : password;

    if (loginController->login(id, password)) {
        out_fp << "2.1. 로그인" << std::endl;
        out_fp << "> " << id << password << std::endl;
    } else {
        out_fp << "2.1. 로그인" << std::endl;
        out_fp << "> " << "login failed" << std::endl;
    }
}