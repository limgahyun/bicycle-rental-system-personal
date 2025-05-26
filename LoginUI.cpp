#include "LoginUI.h"
#include <iostream>
#include <string>

LoginUI::LoginUI() {
    loginController = new LoginController();
}

void LoginUI::requestLogin() {
    std::string id, password;
    
    // In a real implementation, this would read from input.txt
    // For now, we'll use console input for demonstration
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> password;

    if (loginController->login(id, password)) {
        std::cout << "Login successful. Welcome " << id << "!" << std::endl;
    } else {
        std::cout << "Login failed. Invalid ID or password." << std::endl;
    }
}

void LoginUI::start() {
    requestLogin();
} 