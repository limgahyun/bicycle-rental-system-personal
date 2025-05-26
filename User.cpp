#include "User.h"

using namespace std;

User::User() : isLoggedIn(false) {}

User::User(string id, string password) : userId(id), password(password), userRole(USER), isLoggedIn(false) {}

/*
	함수 이름 : User::findUserById()
	기능	 : 해당 id를 가진 user 찾기
	전달 인자 : id
	반환값    : 해당 id를 가진 user 찾기 성공 여부
*/
bool User::findUserById(string searchId) const {
    return this->userId == searchId;
}

/*
	함수 이름 : User::checkPassword()
	기능	 : 해당 password가 일치하는지 확인
	전달 인자 : password
	반환값    : 해당 password가 일치하는지 여부
*/
bool User::checkPassword(string inputPassword) const {
    return this->password == inputPassword;
}

/*
	함수 이름 : User::setLoggedIn()
	기능	 : 로그인 상태 변경
	전달 인자 : 로그인 상태
	반환값    : 없음
*/
void User::setLoggedIn(bool status) {
    this->isLoggedIn = status;
}

/*
	함수 이름 : User::getLoggedIn()
	기능	 : 로그인 상태 반환
	전달 인자 : 없음
	반환값    : 로그인 상태
*/
bool User::getLoggedIn() const {
    return isLoggedIn;
}

/*
	함수 이름 : User::getId()
	기능	 : 해당 user의 id 반환
	전달 인자 : 없음
	반환값    : 해당 user의 id
*/
string User::getId() const {
    return userId;
} 