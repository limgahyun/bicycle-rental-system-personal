#include "LogoutController.h"

LogoutController::LogoutController() {}

/*
    함수 이름 : LogoutController::logout()
    기능	  : 현재 로그인된 사용자를 로그아웃
    전달 인자 : 없음
    반환값    : 로그아웃된 사용자의 ID (실패시 빈 문자열)
*/
string LogoutController::logout() {
    UserCollection* userCollection = UserCollection::getInstance();
    User* currentUser = userCollection->getCurrentUser();
    if (currentUser != nullptr) {
        string userId = currentUser->getId();
        userCollection->logout();
        return userId;
    }
    return "";
}