#include "Admin.h"
#include <iostream>

Admin::Admin(const std::string& fName, const std::string& lName, int age,
             const std::string& login, const std::string& pass, int level)
    : User(fName, lName, age, login, pass), adminLevel(level) {}

void Admin::displayInfo() const {
    std::cout << "Администратор: " << firstName << " " << lastName 
              << " (Уровень: " << adminLevel << ")\n";
}

void Admin::changePassword(const std::string& newPass) {
    password = newPass;
    std::cout << "Изменение пароля для: " << login << "\n";
}

void Admin::setAdminLevel(int level) { adminLevel = level; }
int Admin::getAdminLevel() const { return adminLevel; }