#ifndef USER_COLLECTION_H
#define USER_COLLECTION_H

#include <vector>
#include "Member.h"
#include "User.h"

using namespace std;

/*
    class: UserCollection
    description: 사용자 관리를 위한 collection 클래스
*/
class UserCollection {
private:
    static UserCollection* instance;
    vector<Member*> members;
    User* currentUser;
    User adminUser;

    // Private constructor for singleton
    UserCollection();

public:
    static UserCollection* getInstance();
    
    // User management
    void addMember(Member* member);
    Member* findMemberById(const string& id);
    const vector<Member*>& getMembers() const;
    
    // Login/Logout management
    bool login(const string& id, const string& password);
    void logout();
    User* getCurrentUser() const;
    
    // Destructor
    ~UserCollection();
};

#endif