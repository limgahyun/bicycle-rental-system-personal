#include "LogoutController.h"

/*
    함수 이름 : LogoutController::LogoutController()
    기능	  : LogoutController 생성자
    전달 인자 : 없음
    반환값    : 없음
*/
LogoutController::LogoutController() {
    currentUser = nullptr;
}

/*
    함수 이름 : LogoutController::logout()
    기능	  : 현재 로그인된 사용자를 로그아웃
    전달 인자 : 없음
    반환값    : 로그아웃된 사용자의 ID (실패시 빈 문자열)
*/
string LogoutController::logout() {
    if (currentUser != nullptr) {
        string userId = currentUser->getId();  // Get user ID before nulling the pointer
        currentUser = nullptr;
        return userId;
    }
    return "";
}