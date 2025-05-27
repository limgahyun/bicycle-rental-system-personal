#include "LoginController.h"

LoginController::LoginController() {}

/*
    함수 이름 : LoginController::login()
    기능	  : 로그인
    전달 인자 : id - 사용자 아이디, password - 사용자 비밀번호
    반환값    : 로그인 성공 여부
*/
bool LoginController::login(string id, string password) {
    return UserCollection::getInstance()->login(id, password);
}