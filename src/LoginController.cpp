#include "LoginController.h"
#include "SignUpController.h"
#include <vector>

using namespace std;

static User user;

LoginController::LoginController() : currentUser(nullptr), adminUser("admin", "admin") {}


/*
	함수 이름 : LoginController::login()
	기능	 : id와 password를 통해 해당 user를 상태로 변경
	전달 인자 : id, password
	반환값    : 로그인 성공 여부
*/
bool LoginController::login(string id, string password) {
   // 1. Admin 검사
    if (adminUser.findUserById(id) && adminUser.checkPassword(password)) {
        adminUser.setLoggedIn(true);
        currentUser = &adminUser;
        return true;
    }

    // 2. Member 목록에서 검사
    const auto& members = SignUpController::getMembers();
    for (const auto& member : members) {
        if (member.findUserById(id) && member.checkPassword(password)) {
            // 주의: 복사를 위해 new 사용
            currentUser = new Member(member);  
            currentUser->setLoggedIn(true);
            return true;
        }
    }
    return false;
}

/*
	함수 이름 : LoginController::getCurrentUser()
	기능	 : 현재 로그인한 user 반환
	전달 인자 : 없음
	반환값    : 현재 로그인한 user
*/
User* LoginController::getCurrentUser() const {
    return currentUser;
} 