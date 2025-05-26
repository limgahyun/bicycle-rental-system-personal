#include "LoginController.h"
#include <vector>

using namespace std;

static vector<User> users;

LoginController::LoginController() : currentUser(nullptr) {
    if (users.empty()) {
        users.push_back(User("user1", "pass1"));
        users.push_back(User("user2", "pass2"));
    }
}

/*
	함수 이름 : LoginController::login()
	기능	 : id와 password를 통해 해당 user를 상태로 변경
	전달 인자 : id, password
	반환값    : 로그인 성공 여부
*/
bool LoginController::login(string id, string password) {
    for (auto& user : users) {
        if (user.findUserById(id)) {
            if (user.checkPassword(password)) {
                user.setLoggedIn(true);
                currentUser = &user;
                return true;
            }
            return false;
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