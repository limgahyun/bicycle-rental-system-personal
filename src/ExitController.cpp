#include "ExitController.h"

ExitController::ExitController() {}

/*
    함수 이름 : ExitController::exit()
    기능	  : 프로그램 종료 처리
    전달 인자 : 없음
    반환값    : 없음
*/
void ExitController::exit() {
    // 현재 로그인된 사용자가 있다면 로그아웃
    UserCollection* userCollection = UserCollection::getInstance();
    User* currentUser = userCollection->getCurrentUser();
    if (currentUser != nullptr) {
        userCollection->logout();
    }
} 