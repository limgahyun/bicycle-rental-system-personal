#include "LoginController.h"
#include <vector>

// Simulating a database of users
static std::vector<User> users;

// Initialize users in constructor
LoginController::LoginController() : currentUser(nullptr) {
    if (users.empty()) {
        users.push_back(User("user1", "pass1"));
        users.push_back(User("user2", "pass2"));
    }
}

bool LoginController::login(std::string id, std::string password) {
    for (auto& user : users) {
        if (user.findUserById(id)) {
            if (user.checkPassword(password)) {
                user.setLoggedIn(true);
                currentUser = &user;
                return true;
            }
            return false; // Password incorrect
        }
    }
    return false; // User not found
}

void LoginController::logout() {
    if (currentUser != nullptr) {
        currentUser->setLoggedIn(false);
        currentUser = nullptr;
    }
}

User* LoginController::getCurrentUser() const {
    return currentUser;
} 