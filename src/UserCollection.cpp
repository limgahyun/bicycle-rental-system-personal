#include "UserCollection.h"

// 정적 인스턴스 초기화
UserCollection* UserCollection::instance = nullptr;

UserCollection::UserCollection() : currentUser(nullptr), adminUser("admin", "admin") {}

/*
	함수 이름 : UserCollection::getInstance()
	기능	 : 인스턴스 반환
	전달 인자 : 없음
	반환값    : 인스턴스
*/
UserCollection* UserCollection::getInstance() {
    if (instance == nullptr) {
        instance = new UserCollection();
    }
    return instance;
}

/*
	함수 이름 : UserCollection::addMember()
	기능	 : 멤버 추가
	전달 인자 : 멤버 포인터
	반환값    : 없음
*/
void UserCollection::addMember(Member* member) {
    members.push_back(member);
}

/*
	함수 이름 : UserCollection::findMemberById()
	기능	 : 멤버 찾기
	전달 인자 : 멤버 아이디
	반환값    : 멤버 포인터
*/
Member* UserCollection::findMemberById(const string& id) {
    for (Member* member : members) {
        if (member->findUserById(id)) {
            return member;
        }
    }
    return nullptr;
}

/*
	함수 이름 : UserCollection::getMembers()
	기능	 : 멤버 목록 반환
	전달 인자 : 없음
	반환값    : 멤버 포인터 벡터
*/
const vector<Member*>& UserCollection::getMembers() const {
    return members;
}

/*
	함수 이름 : UserCollection::login()
	기능	 : 로그인
	전달 인자 : 멤버 아이디, 멤버 비밀번호
	반환값    : 로그인 성공 여부
*/
bool UserCollection::login(const string& id, const string& password) {
    // 관리자 로그인 확인
    if (adminUser.findUserById(id) && adminUser.checkPassword(password)) {
        currentUser = &adminUser;
        currentUser->setLoggedIn(true);
        return true;
    }

    // 멤버 로그인 확인
    Member* member = findMemberById(id);
    if (member != nullptr && member->checkPassword(password)) {
        currentUser = member;
        currentUser->setLoggedIn(true);
        return true;
    }

    return false;
}

/*
	함수 이름 : UserCollection::logout()
	기능	 : 로그아웃
	전달 인자 : 없음
	반환값    : 없음
*/
void UserCollection::logout() {
    if (currentUser != nullptr) {
        currentUser->setLoggedIn(false);
        currentUser = nullptr;
    }
}

/*
	함수 이름 : UserCollection::getCurrentUser()
	기능	 : 현재 사용자 반환
	전달 인자 : 없음
	반환값    : 현재 사용자 포인터
*/
User* UserCollection::getCurrentUser() const {
    return currentUser;
}

/*
	함수 이름 : UserCollection::~UserCollection()
	기능	 : 소멸자
	전달 인자 : 없음
	반환값    : 없음
*/
UserCollection::~UserCollection() {
    // 멤버 정리
    for (Member* member : members) {
        delete member;
    }
    members.clear();
}