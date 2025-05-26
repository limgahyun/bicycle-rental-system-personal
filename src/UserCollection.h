#ifndef USER_COLLECTION_H
#define USER_COLLECTION_H

#include <vector>
#include "Member.h"
#include "User.h"

using namespace std;

/*
    class: UserCollection
    description: 사용자 관리를 위한 entity 클래스
*/
class UserCollection {
private:
    static UserCollection* instance;
    vector<Member*> members;
    User* currentUser;
    User adminUser;

    UserCollection();

public:
    static UserCollection* getInstance();
    
    // 멤버 관리
    void addMember(Member* member);
    Member* findMemberById(const string& id);
    const vector<Member*>& getMembers() const;
    
    // 로그인/로그아웃 관리
    bool login(const string& id, const string& password);
    void logout();
    User* getCurrentUser() const;
    
    // 소멸자
    ~UserCollection();
};

#endif