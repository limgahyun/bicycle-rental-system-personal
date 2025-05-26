#include "UserCollection.h"

// Initialize static instance
UserCollection* UserCollection::instance = nullptr;

UserCollection::UserCollection() : currentUser(nullptr), adminUser("admin", "admin") {}

UserCollection* UserCollection::getInstance() {
    if (instance == nullptr) {
        instance = new UserCollection();
    }
    return instance;
}

void UserCollection::addMember(Member* member) {
    members.push_back(member);
}

Member* UserCollection::findMemberById(const string& id) {
    for (Member* member : members) {
        if (member->findUserById(id)) {
            return member;
        }
    }
    return nullptr;
}

const vector<Member*>& UserCollection::getMembers() const {
    return members;
}

bool UserCollection::login(const string& id, const string& password) {
    // Check admin login
    if (adminUser.findUserById(id) && adminUser.checkPassword(password)) {
        currentUser = &adminUser;
        currentUser->setLoggedIn(true);
        return true;
    }

    // Check member login
    Member* member = findMemberById(id);
    if (member != nullptr && member->checkPassword(password)) {
        currentUser = member;
        currentUser->setLoggedIn(true);
        return true;
    }

    return false;
}

void UserCollection::logout() {
    if (currentUser != nullptr) {
        currentUser->setLoggedIn(false);
        currentUser = nullptr;
    }
}

User* UserCollection::getCurrentUser() const {
    return currentUser;
}

UserCollection::~UserCollection() {
    // Clean up members
    for (Member* member : members) {
        delete member;
    }
    members.clear();
}